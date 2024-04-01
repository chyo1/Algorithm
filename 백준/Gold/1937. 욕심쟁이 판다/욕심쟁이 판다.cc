#include <stdio.h>
int map[500][500], DP[500][500];
int n;
int MAX(int a, int b) { return a > b ? a : b; }
int DFS(int x, int y) {
	if (DP[x][y]) return DP[x][y];
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int nx, ny, i,j;
	for (i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n&&map[x][y] < map[nx][ny])
			DP[x][y] = MAX(DFS(nx, ny) + 1, DP[x][y]);
	}
	if (!DP[x][y]) DP[x][y] = 1;
	return DP[x][y];
}
int main() {
	int i, j, m = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			DFS(i, j);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			m = MAX(DP[i][j], m);
		}
	}
	printf("%d", m);
	return 0;
}