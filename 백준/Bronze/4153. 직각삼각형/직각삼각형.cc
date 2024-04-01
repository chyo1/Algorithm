#include <stdio.h>
int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (!a && !b && !c) break;

		a *= a, b *= b, c *= c;
		if (a + b == c || a + c == b || b + c == a) printf("right\n");
		else printf("wrong\n");

	}
	return 0;
}