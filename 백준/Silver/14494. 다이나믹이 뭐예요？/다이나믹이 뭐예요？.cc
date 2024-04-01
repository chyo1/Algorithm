#include <stdio.h>

unsigned int DP[1001][1001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= 1000; i++) DP[i][1] = DP[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			DP[i][j] = (DP[i - 1][j - 1] + DP[i][j - 1] + DP[i - 1][j])%1000000007;
		}
	}
	printf("%d", DP[n][m]);
	return 0;
}