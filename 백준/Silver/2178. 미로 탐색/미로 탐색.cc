#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>> Q;
int N, M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[100][100], visited[100][100];
int BFS();
int main() {

	int i, j;
	char c;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%c", &c); //\n
		for (j = 0; j < M; j++) {
			scanf("%c", &c);
			map[i][j] = c - '0';
		}
	}
	BFS();
	printf("%d", visited[N - 1][M - 1]);
	return 0;
}
int BFS() {
	int x, y;
	Q.push({ 0, 0 });
	visited[0][0] = 1;
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = x + dx[i], n_y = y + dy[i];
			if (0 <= n_x && n_x < N && 0 <= n_y && n_y < M
				&& !visited[n_x][n_y] && map[n_x][n_y] == 1) {
				Q.push({ n_x,n_y });
				visited[n_x][n_y] = visited[x][y] + 1;
			}
		}

	}
	return 0;
}