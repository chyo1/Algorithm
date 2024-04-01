#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a > b) {
		if (b > c) // a > b > c
			printf("%d %d %d", c, b, a);
		else {
			if (a > c) // a > c >= b
				printf("%d %d %d", b, c, a);
			else // c >= a > b
				printf("%d %d %d", b, a, c);
		}
	}
	else { // b >= a
		if (a > c) // b >= a > c
			printf("%d %d %d", c, a, b);
		else {
			if (c > b) // c > b >= a
				printf("%d %d %d", a, b, c);
			else // b >= c >= a
				printf("%d %d %d", a, c, b);
		}
	}
	return 0;
}