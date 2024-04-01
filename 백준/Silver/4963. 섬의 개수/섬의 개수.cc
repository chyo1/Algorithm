#include <stdio.h>
#include <string.h>
int map[50][50], visited[50][50];
int w, h, cnt;
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int DFS(int x, int y) {
	if (x<0 || x>=h || y<0 || y>=w) return 0;
	visited[x][y] = 1;

	for (int i = 0; i < 8; i++) {
		int n_x = x + dx[i], n_y = y + dy[i];
		if (map[n_x][n_y] == 1 && !visited[n_x][n_y])
			DFS(n_x, n_y);
	}
	return 0;
}
int main() {

	int i, j;
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);

		cnt = 0;
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
	return 0;
}