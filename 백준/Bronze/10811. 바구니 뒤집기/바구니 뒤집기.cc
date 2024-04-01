#include <stdio.h>
int main() {
	int N, M, i, j;
	int bucket[101], tmp[101];

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) bucket[i] = i;

	for (int m = 0; m < M; m++) {
		scanf("%d %d", &i, &j);
		for (int r = i; r <= j; r++) tmp[i + j - r] = bucket[r];
		for (int r = i; r <= j; r++) bucket[r] = tmp[r];
	}

	for (int i = 1; i <= N; i++) printf("%d ", bucket[i]);

	return 0;
}