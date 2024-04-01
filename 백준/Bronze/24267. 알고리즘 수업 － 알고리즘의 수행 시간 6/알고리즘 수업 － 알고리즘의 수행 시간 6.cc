#include <stdio.h>
int main() {
	long long n, cnt = 0;
    
	scanf("%lld", &n);

	for (int i = 1; i < n; i++) {
		cnt += (n - i)*(n - i - 1) / 2;
	}
    
	printf("%lld\n3", cnt);
	return 0;
}