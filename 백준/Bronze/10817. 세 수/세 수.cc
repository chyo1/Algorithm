#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) {
		// a>b>c
		if (b > c) printf("%d", b);
		//a>c>=b
		else if (a > c) printf("%d", c);
		//c>=a>b
		else printf("%d", a);
	}
	//b>=a
	else {
		//b>=a>c
		if (a > c) printf("%d", a);
		// b>=c>=a
		else if (b > c) printf("%d", c);
		// c>=b>=a
		else printf("%d", b);
	}
	return 0;
}