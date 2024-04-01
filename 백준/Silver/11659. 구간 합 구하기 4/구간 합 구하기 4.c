#include <stdio.h>
int mat[100001];
long long int sum[100001] = { 0, };
int main() {
	int N, M, k;
	int i, j;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &mat[i]);
		if (i == 0) sum[i] += mat[i];
		else sum[i] = sum[i - 1] + mat[i];
	}
	for (k = 0; k < M; k++) {
		scanf("%d %d", &i, &j);
		if (i == 1) printf("%d\n", sum[j - 1]);
		else printf("%d\n", sum[j - 1] - sum[i - 2]);
	}
	return 0;
}