#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[101], visited[101];

int BFS(int R) {
	int now, cnt;
	int next;
	queue <pair<int, int>> Q;

	// init
	visited[R] = 1;
	Q.push({ R,1 });

	while (!Q.empty()) {
		now = Q.front().first, cnt = Q.front().second;
		Q.pop();

		int now_loc = map[now];
		for (int i = 6; i >= 1; i--) {
			next = now_loc + i;

			if (next > 100 || visited[next]) continue;
			if (next == 100) return cnt;

			visited[next] = visited[map[next]] = cnt + 1;
			Q.push({ next,cnt + 1 });

		}
	}
}

int main() {
	int N, M;
	int x, y, u, v;

	for (int i = 1; i <= 100; i++) map[i] = i;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		map[x] = y;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		map[u] = v;
	}

	printf("%d", BFS(1));

	return 0;
}