#include <stdio.h>
#include <math.h>
int main() {
	int n, i;
	long long int t[36] = { 1, };
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			t[i] += t[j] * t[abs((i - 1) - j)];
		}
	}
	printf("%lld ", t[n]);
	return 0;
}