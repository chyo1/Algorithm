#include <stdio.h>
int pas(int n, int k);
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", pas(n, k));
	return 0;
}
int pas(int n, int k) {
	int P[31][31];
	int i, j;

	P[0][0] = P[1][0] = P[1][1] = 1;
	for (i = 2; i <= n; i++) {
		P[i][0] = P[i][i] = 1;
		for (j = 1; j < i; j++) {
			P[i][j] = P[i - 1][j - 1] + P[i - 1][j];
		}
	}
	return P[n - 1][k - 1];
}