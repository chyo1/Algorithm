#include <stdio.h>
int main() {
	int N, M;
	int i, j, k;
	int mat1[101], mat2[101];
	scanf("%d %d", &N, &M);

	// init
	for (int m = 1; m <= N; m++) mat1[m] = mat2[m] = m;

	for (int m = 0; m < M; m++) {
		scanf("%d %d %d", &i, &j, &k);
		int start = i;

		for (int l = k; l <= j; l++) mat2[start++] = mat1[l];
		for (int l = i; l <= k - 1; l++) mat2[start++] = mat1[l];

		for (int l = i; l <= j; l++) mat1[l] = mat2[l];
	}

	for (int m = 1; m <= N; m++) printf("%d ", mat2[m]);
	return 0;
}