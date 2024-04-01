#include <stdio.h>
int main() {
	long long n, cnt = 0;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++)
			cnt++;
	}
	printf("%lld\n2", cnt);
	return 0;
}