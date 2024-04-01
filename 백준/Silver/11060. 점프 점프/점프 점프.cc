#include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std;
int MIN(int a, int b) { return a < b ? a : b; }
int main() {
	int N, i, j;
	int A[1001], DP[1001] = { 0, };
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	fill(DP + 1, DP + N, INT_MAX);

	for (i = 0; i < N; i++) {
		if (DP[i] == INT_MAX) {
			DP[N - 1] = -1;
			break;
		}
		for (j = 1; j <= A[i]; j++) {
			if (i + j >= N) continue;
			DP[i + j] = MIN(DP[i] + 1, DP[i + j]);
		}
	}
	if (DP[N - 1] == INT_MAX) DP[N - 1] = -1;
	printf("%d", DP[N - 1]);
	return 0;
}