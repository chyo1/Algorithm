#include <stdio.h>
int main() {
	int N, K, A[14], cnt = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = N - 1; i >= 0; i--) {
		cnt += K / A[i];
		K %= A[i];
	}
	printf("%d", cnt);
	return 0;
}