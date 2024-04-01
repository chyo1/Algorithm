#include <stdio.h>
int A[60][10];
void Print(int num, int R, int C) {
	if (num / 10 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%1d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 100 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%2d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 1000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%3d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 10000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%4d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 100000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%5d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 1000000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%6d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 10000000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%7d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 100000000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%8d ", A[i][j]);
			printf("\n");
		}
	}
	else if (num / 1000000000 == 0) {
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) printf("%9d ", A[i][j]);
			printf("\n");
		}
	}
}
void D(int R, int C, int r, int c) {
	int dir_x[4] = { 0,-1,0,1 }, dir_y[4] = { 1,0,-1,0 };
	int dir = 0;
	int turn = 1, cnt = 1, fill = 0;

	if (0 <= r && r <= R && 0 <= c && c <= C) A[r][c] = 1, fill++;
	while (1) {

		// turn만큼 이동을 2번씩 반복함
		for (int k = 0; k < 2; k++) {

			// 같은 방향으로 turn만큼 이동
			for (int i = 0; i < turn; i++) {
				cnt++;
				r += dir_x[dir], c += dir_y[dir];
				if (0 <= r && r <= R && 0 <= c && c <= C) {
					A[r][c] = cnt;
					if (++fill == (R + 1) * (C + 1)) return Print(cnt, R, C);
				}
			}
			// 움직일 방향
			dir = (dir + 1) % 4;
		}
		turn++;
	}
}

int main() {
	int r1, r2, c1, c2, sx = 0, sy = 0;

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	if (!r1 && !r2 && !c1 && !c2) { printf("1"); return 0; }

	// 시작 좌표 (0,0)으로 맞춰줌
	sx -= r1, r2 -= r1, r1 -= r1;
	sy -= c1, c2 -= c1, c1 -= c1;


	D(r2, c2, sx, sy);
	return 0;
}
