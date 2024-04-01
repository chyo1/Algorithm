#include <stdio.h>

int main() {
	int A;
	scanf("%d", &A);
	if (A / 1000) printf("20");
	else if (A / 100 && A / 100 != 1) printf("%d", A / 100 + A % 100);
	else printf("%d", A / 10 + A % 10);
	return 0;
}