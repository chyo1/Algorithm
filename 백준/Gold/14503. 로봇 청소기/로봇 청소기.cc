#include <stdio.h>
using namespace std;

int map[51][51], cnt = 0;
int N, M;
void Clean(int r, int c, int d) {
	// 갈 수 없는 경우 종료
	if (r < 0 || r >= N || c < 0 || c >= M || map[r][c] == 1) return;
	if (!map[r][c]) map[r][c] = 2, cnt++;

	int move[4][2] = { {-1,0} ,{0, -1}, {1,0}, {0,1} };
	int x = r, y = c, dir = d;

	for (int i = d + 1; i <= d + 4; i++) {
		int dir = i % 4;
		int nx = r + move[dir][0], ny = c + move[dir][1];

		// 청소 안 된 칸일 경우에만 이동
		if (map[nx][ny]) continue;
		return Clean(nx, ny, dir);
	}

	// 주변에 청소 안 된 칸이 없을 경우 후진
	return Clean(r - move[d][0], c - move[d][1], d);
}
int main() {
	int r, c, d;

	// input
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	if (d == 1) d = 3;
	else if (d == 3) d = 1;
	Clean(r, c, d);

	printf("%d", cnt);
	return 0;
}