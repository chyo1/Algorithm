#include <stdio.h>
int mat[1025][1025], sum[1025][1025];
int main() {
	int N, M, i, j;
	long long int total;
	int x1, x2, y1, y2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &mat[i][j]);
			sum[i][j] = mat[i][j];
			if (j > 0) sum[i][j] += sum[i][j - 1];
		}
	}
	for (i = 0; i < M; i++) {
		total = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == x2 && y1 == y2) total = sum[x2][y2] - sum[x2][y2 - 1]; // 범위가 한 정점인 경우
		else {
			for (j = x1; j <= x2; j++) {
				total += sum[j][y2];
				if (y1 > 1) total -= sum[j][y1 - 1];
			}
		}
		printf("%lld\n", total);
	}
	return 0;
}