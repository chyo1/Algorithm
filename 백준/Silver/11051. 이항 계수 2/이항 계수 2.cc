#include <stdio.h>
int C[1001][1001];
int nCk(int n, int k) {
	int i, j;
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (i = 2; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007;
		}
	}
	return C[n][k];
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", nCk(N, K));
	return 0;
}