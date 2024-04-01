#include <stdio.h>

int main() {
	int N, K,i, cnt = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		if (N%i == 0) cnt++;
		if (cnt == K) break;
	}
	if (cnt < K) printf("0");
	else printf("%d", i);
	return 0;
}