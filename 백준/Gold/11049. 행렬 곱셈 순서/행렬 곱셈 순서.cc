#include <stdio.h>
#include <climits>
int N, Row[501], Col[501];
int D[501][501];
int min(int a, int b) { return a < b ? a : b; }
int main() {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &Row[i], &Col[i]);

	for (int step = 1; step < N; step++) {
		for (int start = 1; start <= N - step; start++) {
			D[start][start + step] = INT_MAX;
			for (int mid = start; mid < start + step; mid++)
				D[start][start + step] = min(D[start][start + step],
					D[start][mid] + D[mid + 1][start + step] + Row[start] * Col[start + step] * Col[mid]);
		}
	}
	printf("%d", D[1][N]);
	return 0;
}