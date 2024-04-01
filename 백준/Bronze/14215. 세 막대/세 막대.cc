#include <stdio.h>
int main() {
	int a, b, c, l1, l2, l3;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && a == c && b == c) printf("%d", 3 * a);
	else {
		if ((a > b&&a > c) || (a >= b && a > c) || (a > b&&a >= c)) l1 = a, l2 = b, l3 = c;
		if ((b > a&&b > c) || (b >= a && b > c) || (b > a&&b >= c)) l1 = b, l2 = a, l3 = c;
		if ((c > a&&c > b) || (c >= a && c > b) || (c > a&&c >= b)) l1 = c, l2 = b, l3 = a;

		if (l1 >= l2 + l3) printf("%d", 2 * (l2 + l3) - 1);
		else printf("%d", l1 + l2 + l3);
	}

	return 0;
}