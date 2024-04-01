#include <stdio.h>
int main() {
	int n1, n2, n2_1, n2_10, n2_100;
	scanf("%d%d", &n1, &n2);
	n2_1 = n2 % 10;
	n2_10 = (n2 / 10) % 10;
	n2_100 = n2 / 100;
	printf("%d\n", n1*n2_1);
	printf("%d\n", n1*n2_10);
	printf("%d\n", n1*n2_100);
	printf("%d", n1*n2);
	return 0;
}