#include <stdio.h>
#include <stdlib.h>
int map[50][50], visited[50][50];
int T, M, N, K;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };  // up down left right
int DFS(int a, int b);
int main() {

	int r, c;
	int i, j, t, cnt;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &M, &K);

		// 초기화
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++)
				map[i][j] = visited[i][j] = 0;
		}

		// 배추위치
		for (i = 0; i < K; i++) {
			scanf("%d %d", &r, &c);
			map[r][c] = 1;
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}
int DFS(int a, int b) {
	int i;
	if (a < 0 || a >= N || b < 0 || b >= M || !map[a][b] || visited[a][b] == 1) return 0;
	visited[a][b] = 1;
	for (i = 0; i < 4; i++) DFS(a + di[i], b + dj[i]);
	return 0;
}