#include <stdio.h>
#include <queue>
using namespace std;

int Maze[100][100], Cnt[100][100];
queue <pair<int, int>> Q;

int Dijkstra(int N, int M) {
	int move[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int x, y, nx, ny;

	// init
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			Cnt[i][j] = 1000000;
	}
	Cnt[0][0] = 0;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		x = Q.front().first, y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + move[i][0], ny = y + move[i][1];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {

				if (Cnt[nx][ny] > Cnt[x][y] + Maze[nx][ny]) {
					Cnt[nx][ny] = Cnt[x][y] + Maze[nx][ny];
					Q.push({ nx,ny });
				}
			}
		}

	}
	return Cnt[N - 1][M - 1];
}

int main() {
	int M, N;
	char s[101];
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < M; j++) {
			Maze[i][j] = s[j] - '0';
		}
	}
	printf("%d", Dijkstra(N, M));
	return 0;
}