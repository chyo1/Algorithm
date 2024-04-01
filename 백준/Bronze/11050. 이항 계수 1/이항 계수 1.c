#include <stdio.h>
int main() {
	int N, K, i, result = 1;
	scanf("%d %d", &N, &K);
	for (i = 0; i < K; i++) {
		result *= N--;
	}
	for (i = 2; i <= K; i++) {
		result /= i;
	}
	printf("%d", result);
	return 0;
}