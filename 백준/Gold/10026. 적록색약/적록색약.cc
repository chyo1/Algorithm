#include <stdio.h>
#define MAX 105
char map[MAX][MAX];
int visited[MAX][MAX], visited_gb[MAX][MAX];
int N;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
char RGB[3] = { 'R','G','B' };
int DFS(int a, int b, char rgb);
int DFS_gb(int a, int b, char rgb);
int main() {
	int i, j;
	int cnt = 0, cnt_gb = 0;
	char c;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%c", &c); //\n
		for (j = 0; j < N; j++) {
			scanf("%c", &map[i][j]);
		}
	}

	// 정상
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j, map[i][j]);
				cnt++;
			}
		}
	}

	// 적록색맹
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!visited_gb[i][j]) {
				DFS_gb(i, j, map[i][j]);
				cnt_gb++;
			}
		}
	}

	printf("%d %d", cnt, cnt_gb);
	return 0;
}
int DFS(int a, int b, char rgb) {
	if (a < 0 || a >= N || b < 0 || b >= N || visited[a][b] == 1) return 0;
	visited[a][b] = 1;
	int i;
	for (int i = 0; i < 4; i++) {
		if (map[a + di[i]][b + dj[i]] == rgb) {
			rgb = map[a][b];
			DFS(a + di[i], b + dj[i], rgb);
		}
	}
	return 0;
}
int DFS_gb(int a, int b, char rgb) {
	if (a < 0 || a >= N || b < 0 || b >= N || visited_gb[a][b] == 1) return 0;
	visited_gb[a][b] = 1;
	int i;
	for (int i = 0; i < 4; i++) {
		if (rgb == 'R' || rgb == 'G') {
			if (map[a + di[i]][b + dj[i]] == 'R' || map[a + di[i]][b + dj[i]] == 'G') {
				rgb = map[a][b];
				DFS_gb(a + di[i], b + dj[i], rgb);
			}
		}
		else if (rgb == 'B') {
			if (map[a + di[i]][b + dj[i]] == 'B') {
				rgb = map[a][b];
				DFS_gb(a + di[i], b + dj[i], rgb);
			}
		}
	}
	return 0;
}