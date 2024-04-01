#include <stdio.h>
int map[50][50], visited[50][50];
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,-1,0,1 };
int N, M, cycle = 0;
int dfs(int i, int j);
int main() {
	int i, j;
	char c;
	scanf("%d %d\n", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%c", &c);
			if (c == 'H') map[i][j] = -1;
			else map[i][j] = c - '0';

			visited[i][j] = -1; // 방문 초기화
		}
		 scanf("%c", &c); // \n
	}
	int res = dfs(0, 0);
	if (cycle == 1) printf("-1");
	else printf("%d", res);
	printf("");
	return 0;
}
int dfs(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M || cycle == 1 || map[i][j] == -1) return 0; // 갈 수 없으므로 0

	int k, r, cal = -1;

	if (visited[i][j] == -1) {// white
		visited[i][j] = 0;
		for (k = 0; k < 4; k++) {
			r = dfs(i + di[k] * map[i][j], j + dj[k] * map[i][j]) + 1;
			if (cal < r) cal = r; // 최대 횟수
		}
		visited[i][j] = cal;
		return cal;
	}
	else if (visited[i][j] == 0) { //gray
		cycle = 1;
		return 0;		// cycle 생성됨.
	}
	else return visited[i][j]; // black
}