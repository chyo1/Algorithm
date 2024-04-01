#include <stdio.h>
int main() {
	int N, M, K;
	int DP[16][16];
	int kx, ky, r1, r2;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < 16; i++) DP[0][i] = DP[i][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}

	if (!K) {
		printf("%d", DP[N - 1][M - 1]);
		return 0;
	}
	else if (K%M == 0) kx = K / M - 1, ky = M - 1;
	else kx = K / M, ky = (K%M) - 1;

	printf("%d", DP[kx][ky] * DP[N - kx - 1][M - ky - 1]);
	return 0;
}