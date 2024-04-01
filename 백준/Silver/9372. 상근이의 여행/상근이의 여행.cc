#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> V[1001];
void Init_V(int N) {
	for (int i = 1; i <= N; i++)
		V[i].clear();
}

int Find_min(int N) {
	queue<int> Q;
	vector<bool> visited(1001, false);

	Q.push(1);
	visited[1] = true;
	int now, cnt = 0;
	while (!Q.empty()) {
		now = Q.front();
		Q.pop();

		for (int i : V[now]) {
			if (visited[i]) continue;
			Q.push(i);
			visited[i] = true;
			cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	int T, N, M, s, e;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &s, &e);
			V[s].push_back(e);
			V[e].push_back(s);
		}
		// Search
		printf("%d\n", Find_min(N));

		Init_V(N);
	}
	return 0;
}