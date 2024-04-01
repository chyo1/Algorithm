#include <stdio.h>
int n0, n1;
int DP0[41] = { 1,0 }, DP1[41] = { 0,1 };
int main() {
	int T, N, i;
	scanf("%d", &T);
	for (i = 2; i <= 40; i++) {
		DP0[i] = DP0[i - 1] + DP0[i - 2];
		DP1[i] = DP1[i - 1] + DP1[i - 2];
	}
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d %d\n", DP0[N], DP1[N]);
	}
	return 0;
}