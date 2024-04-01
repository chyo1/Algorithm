#include <stdio.h>

int map[301][301];
int Get_sum(int sx, int sy, int ex, int ey) {
	int sum = 0;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}
int main() {
	int N, M, K;
	int i, j, x, y;
	scanf("%d %d", &N, &M);
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) scanf("%d", &map[a][b]);
	}
	scanf("%d", &K);
	for (int a = 0; a < K; a++) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n", Get_sum(i, j, x, y));
	}

	return 0;
}