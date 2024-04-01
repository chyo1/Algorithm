#include <stdio.h>
int DP[1000000] = { 0,1,2,3 };
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 4; i <= N; i++) DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
	printf("%d", DP[N]);
	return 0;
}