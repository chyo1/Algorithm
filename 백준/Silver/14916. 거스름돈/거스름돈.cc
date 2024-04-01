#include <stdio.h>
int main() {
	int n, n5, n2;
	scanf("%d", &n);
	n5 = n / 5;
	n -= n5 * 5;
	while (n5 >= 0) {
		if (n % 2 == 0) {
			n2 = n / 2;
			break;
		}
		else n += 5, n5--;
	}
	if (n5 >= 0) printf("%d", n5 + n2);
	else printf("-1");
	return 0;
}