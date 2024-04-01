#include <stdio.h>

#define DIV 1000000000

int main() {
	int N, sum = 0;
	int DP[101][10] = { 0, };
	
	scanf("%d", &N);

	for (int i = 1; i < 10; i++) DP[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
		for (int j = 1; j < 9; j++) {
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1])%DIV;
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum + DP[N][i]) % DIV;
	}
	printf("%d", sum);

	return 0;
}