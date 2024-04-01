#include <stdio.h>
#include <queue>
using namespace std;

bool map[101][101], visited[101][101];
int N, M;
int blue, white;

void BFS(int sx, int sy, int team) {
	queue <pair<int, int>> Q;
	int x, y, nx, ny, cnt = 1;
	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	// init
	Q.push({ sx, sy });
	visited[sx][sy] = true;

	// BFS
	while (!Q.empty()) {
		x = Q.front().first, y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0], ny = y + d[i][1];
			if (map[nx][ny] != team || visited[nx][ny] || nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			
			visited[nx][ny] = true;			
			Q.push({ nx,ny });
			cnt++;
		}
	}

	// power
	if (team) white += cnt * cnt;
	else blue += cnt * cnt;
}

int main() {
	char s[105];
	scanf("%d %d\n", &N, &M);

	// input
	for (int i = 0; i < M; i++) {
		scanf("%s", s);
		for (int j = 0; j < N; j++) {
			if (s[j] == 'W') map[i][j] = 1;
		}
	}

	// BFS
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j])
				BFS(i, j, map[i][j]);
		}
	}

	// print
	printf("%d %d", white, blue);
	return 0;
}