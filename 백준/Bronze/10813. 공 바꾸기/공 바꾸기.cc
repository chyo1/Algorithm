#include <stdio.h>
int main() {
	int N, M, a, b, tmp;
	int bucket[101];

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) bucket[i] = i;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		tmp = bucket[a];
		bucket[a] = bucket[b];
		bucket[b] = tmp;
	}

	for (int i = 1; i <= N; i++) printf("%d ", bucket[i]);

	return 0;
}