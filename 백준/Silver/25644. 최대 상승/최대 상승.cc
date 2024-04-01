#include <stdio.h>
int  A[200000], DP[200000];
int main() {
	int N, min;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	DP[0] = 0, min = A[0];
	for (int i = 1; i < N; i++) {
		if (A[i] < min) min = A[i];
		DP[i] = A[i] - min > DP[i - 1] ? A[i] - min : DP[i - 1];
	}

	printf("%d", DP[N - 1]);
	return 0;
}