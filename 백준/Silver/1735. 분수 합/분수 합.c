#include <stdio.h>
int GCD(int a, int b);
int main() {
	int A, B, C, D;
	int num, den, a;
	scanf("%d %d", &A, &B);
	scanf("%d %d", &C, &D);
	num = A * D + B * C, den = B * D;
	a = GCD(num, den);
	printf("%d %d", num/a,den/a);
	return 0;
}
int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a%b);
}