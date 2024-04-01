#include <stdio.h>
int main() {
	int M, N, i, num, sum = 0, min=0;
	scanf("%d%d", &M, &N);
	for (i = M; i <= N; i++) {
		if (IsPrime(i) == 1) {
			sum += i;
			if (!min) min = i;
		}
	}
	if (!sum) printf("-1");
	else printf("%d\n%d", sum, min);
	return 0;
}
int IsPrime(int n) {
	int i;
	if (n == 1) return 0;
	for (i = 2; i < n; i++) {
		if (n%i == 0) return 0;
	}
	return 1;
}