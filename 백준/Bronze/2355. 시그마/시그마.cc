#include <stdio.h>
#include <math.h>
int main() {
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	if (a == b) printf("%d", a);
	else printf("%lld", ((a + b) * ( abs( (b - a) ) + 1)) / 2);
	return 0;
}