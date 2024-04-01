#include <stdio.h>
#include <string.h>
int N, M;
int map[501][501], DP[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; // down left right
int DFS(int x, int y);
int main() {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	}

	memset(DP, -1, sizeof(DP));
	printf("%d", DFS(0, 0));
	return 0;
}
int DFS(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;
	int n_x, n_y;

	if (DP[x][y] == -1) {
		DP[x][y] = 0;

		for (int i = 0; i < 4; i++) {
			n_x = x + dx[i], n_y = y + dy[i];
			if (0 <= n_x && n_x < N && 0 <= n_y && n_y < M) {
				if (map[n_x][n_y] < map[x][y]) DP[x][y] += DFS(n_x, n_y);
			}
		}
	}
	return DP[x][y];
}