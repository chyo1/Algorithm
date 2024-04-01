#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	a = a * 100 - a * b;

	if (a < 10000) printf("1");
	else printf("0");

	return 0;
}