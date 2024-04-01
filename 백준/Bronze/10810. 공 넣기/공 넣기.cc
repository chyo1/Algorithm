#include <stdio.h>
int main() {
	int N, M, i, j, k;
	int bucket[101] = { 0, };

	scanf("%d %d", &N, &M);

	for (int m = 0; m < M; m++) {
		scanf("%d %d %d", &i, &j,&k);
		for (int r = i; r <= j; r++) bucket[r] = k;
		
	}

	for (int i = 1; i <= N; i++) printf("%d ", bucket[i]);

	return 0;
}