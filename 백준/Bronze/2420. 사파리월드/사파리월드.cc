#include <stdio.h>
int main() {
	long long int N, M, d;
	scanf("%lld %lld", &N, &M);
	d = N - M;
	if (d < 0) d = -d;

	printf("%lld", d);
	return 0;
}