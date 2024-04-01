#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> V[300001];
priority_queue <int, vector<int>, greater<int>> pQ;

void BFS(int start, int dis) {
	queue <pair<int, int>> Q;
	bool visited[300001] = { 0, };
	int now, cnt;

	Q.push({ start,0 });
	visited[start] = true;
	while (!Q.empty()) {
		now = Q.front().first, cnt = Q.front().second;
		Q.pop();

		if (cnt == dis) {
			pQ.push(now);
			continue;
		}

		for (int i : V[now]) {

			if (!visited[i]) {
				Q.push({ i,cnt + 1 });
				visited[i] = true;
			}
		}
	}
}

int main() {
	int N, M, K, X, A, B;
	scanf("%d %d %d %d", &N, &M, &K, &X);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		V[A].push_back(B);
	}
    
	BFS(X, K);
    
	if (pQ.empty()) printf("-1");
	while (!pQ.empty()) {
		printf("%d\n", pQ.top());
		pQ.pop();
	}
    
	return 0;
}