#include <stdio.h>
int main() {
	int n, i;
	long long int fn, fn1 = 1, fn2 = 0;

	scanf("%d", &n);
	if (n == 0) fn = fn2;
	else if (n == 1) fn = fn1;
	for (i = 2; i <= n; i++) {
		fn = fn1 + fn2;
		fn2 = fn1;
		fn1 = fn;
	}
	printf("%lld", fn);
	return 0;
}