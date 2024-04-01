#include <stdio.h>
int MAX(int a, int b) { return a > b ? a : b; }
int main() {
	int N, i, j, max = 1;
	int A[1000], DP[1000];
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	for (i = 0; i < N; i++) DP[i] = 1;
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (A[j] > A[i]) {
				DP[i] = MAX(DP[j] + 1, DP[i]);
				if (DP[i] > max) max = DP[i];
			}
		}
	}
	printf("%d", max);
	return 0;
}