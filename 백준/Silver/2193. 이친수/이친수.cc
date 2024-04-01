#include <stdio.h>
int main() {
	int N;
	unsigned long long int DP[91][2] = { 0,0,0,1,1,0 };
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}
	printf("%llu", DP[N][0] + DP[N][1]);
	return 0;
}