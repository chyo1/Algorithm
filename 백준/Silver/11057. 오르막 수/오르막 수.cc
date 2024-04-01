#include <stdio.h>

#define DIV 10007

int main() {
	int N, sum = 0;
	int DP[1001][10] = { 0, };

	// input
	scanf("%d", &N);

	// init
	for (int i = 0; i < 10; i++) DP[1][i] = 1;
	for (int i = 0; i <= N; i++) DP[i][0] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % DIV;
		}
	}

	// print
	for (int i = 0; i < 10; i++) sum += DP[N][i];
	printf("%d", sum%DIV);
}