#include <stdio.h>
#include <queue>
using namespace std;

bool map[1001][1001], visited[2][1001][1001];
int Min[2][1001][1001];

auto BFS(int N, int M) {
	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	int x, y, nx, ny;
	bool wall;
	queue <pair<pair<int, int>, bool>> Q;

	Q.push({ {0,0},0 });
	visited[0][0][0] = visited[1][0][0] = Min[0][0][0] = Min[1][0][0] = true;

	while (!Q.empty()) {
		x = Q.front().first.first, y = Q.front().first.second, wall = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0], ny = y + d[i][1];

			if (nx < 0 || nx > N || ny < 0 || ny > M) continue;

			if (!map[nx][ny]) {
				if (!wall && !visited[1][nx][ny]) {
					visited[1][nx][ny] = true;
					Min[1][nx][ny] = Min[wall][x][y] + 1;
					Q.push({ {nx,ny},true });
				}
			}
			else {
				if (!visited[wall][nx][ny]) {
					visited[wall][nx][ny] = true;
					Min[wall][nx][ny] = Min[wall][x][y] + 1;
					Q.push({ {nx,ny},wall });
				}
			}
		}
	}
	if (!visited[0][N][M]) {
		if (!visited[1][N][M]) return -1;
		else return Min[1][N][M];
	}
	else {
		if (!visited[1][N][M]) return Min[0][N][M];
		else return Min[0][N][M] < Min[1][N][M] ? Min[0][N][M] : Min[1][N][M];
	}

}
int main() {
	int N, M;
	char s[1003];

	// input
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < M; j++) {
			if (s[j] == '0') map[i][j] = true;
		}
	}

	printf("%d", BFS(N - 1, M - 1));
	return 0;
}