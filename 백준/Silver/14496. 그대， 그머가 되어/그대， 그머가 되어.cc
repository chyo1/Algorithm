#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

queue <pair<int, int>> Q;
vector <int> V[1001];
bool visited[1001];
int BFS(int end) {
	int now, lev;
	while (!Q.empty()) {
		now = Q.front().first, lev = Q.front().second;
		Q.pop();
		for (int i : V[now]) {
			if (visited[i]) continue;
			visited[i] = true;
			if (i == end) return lev;
			else Q.push({ i,lev + 1 });
		}
	}
	return -1;
}
int main() {
	int a, b, N, M, i, j;

	// input
	scanf("%d %d", &a, &b);

	// 바꾸려는 문자가 동일한 경우
	if (a == b) {
		printf("0");
		return 0;
	}

	scanf("%d %d", &N, &M);

	for (int m = 0; m < M; m++) {
		scanf("%d %d", &i, &j);
		V[i].push_back(j);
		V[j].push_back(i);
	}

	
	Q.push({ a,1 });
	printf("%d", BFS(b));

	return 0;
}