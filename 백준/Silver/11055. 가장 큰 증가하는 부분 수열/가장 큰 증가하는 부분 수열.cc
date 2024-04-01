#include <stdio.h>
int MAX(int a, int b) { return a > b ? a : b; }
int main() {
	int N;
	int i, j, max = 1;
	int A[1001], DP[1001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]), DP[i] = A[i];
	for (i = 1; i < N; i++) {
		for (j = 0; j <= i; j++) {
			if (A[j] < A[i]) {
				DP[i] = MAX(DP[j] + A[i], DP[i]);
			}
		}
	}
	for (i = 0; i < N; i++) max = MAX(max, DP[i]);
	printf("%d", max);
	return 0;
}