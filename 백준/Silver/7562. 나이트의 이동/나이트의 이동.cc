#include <stdio.h>
#include <queue>
using namespace std;

int l;
int Moving(int sx, int sy, int ex, int ey) {
	if (sx == ex && sy == ey) return 0;
	int move[8][2] = { {-1,-2}, {-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };
	int x, y, nx, ny, cnt;
	int visited[300][300] = { 0, };

	queue <pair<int, int>> Q;

	Q.push({ sx,sy }); visited[sx][sy] = 1;
	while (!Q.empty()) {
		x = Q.front().first, y = Q.front().second, cnt = visited[x][y];
		Q.pop();

		for (int i = 0; i < 8; i++) {
			nx = x + move[i][0], ny = y + move[i][1];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l || visited[nx][ny]) continue;

			if (nx == ex && ny == ey) return cnt;
			Q.push({ nx,ny });
			visited[nx][ny] = cnt + 1;
		}
	}
}

int main() {
	int T, sx, sy, ex, ey;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &l);
		scanf("%d %d\n%d %d", &sx, &sy, &ex, &ey);
		printf("%d\n", Moving(sx, sy, ex, ey));
	}
	return 0;
}