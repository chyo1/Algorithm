#include <stdio.h>
#include <string.h>
int N, M, cnt, ice = 0;
bool visited[300][300];
int map[300][300], map2[300][300];
void DFS(int x, int y) {
	visited[x][y] = true;
	cnt++;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int i, nx, ny;
	for (i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny] && map[nx][ny]) {
			DFS(nx, ny);
		}
	}
	for (i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && !map[nx][ny]) {
			map2[x][y]--;
		}		
	}
	if (map2[x][y] <= 0) map2[x][y] = 0;
}
void init() {
	ice = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map2[i][j];
			if (map[i][j]) ice++;
		}
	}
}
int main() {
	int i, j;
	int day = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			map2[i][j] = map[i][j];
			if (map[i][j]) ice++;
		};
	}
	
	while (1) {
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					DFS(i, j);
					if (cnt != ice) { // 빙산 분리
						printf("%d", day);
						return 0;
					}
				}
			}
		}
		if (!cnt) break;
		day++;
		init();
		memset(visited, false, sizeof(visited));		
	}
	printf("0");
	return 0;
}
