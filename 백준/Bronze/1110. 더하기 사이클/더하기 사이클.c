#include <stdio.h>
int main() {
	int n, num, n_1, sum, cnt = 0;
	scanf("%d", &n);
	num = n;
	while (1) {
		n_1 = num % 10;
		sum = num / 10 + n_1;
		num = n_1 * 10 + sum % 10;
		cnt++;

		if (num == n) break;
	}
	printf("%d", cnt);
}