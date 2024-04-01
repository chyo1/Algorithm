#include <stdio.h>
int main() {
	int N, i, num, sum=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		sum+=IsPrime(num);
	}
	printf("%d", sum);
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