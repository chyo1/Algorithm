#include <stdio.h>
int get_gcd(int a, int b) {
	if (b == 0) return a;
	return get_gcd(b, a%b);
}
int main() {
	int A, B;
	int gcd, lcm;
	scanf("%d %d", &A, &B);

	gcd = get_gcd(A, B);
	A /= gcd, B /= gcd;

	lcm = A * B*gcd;

	printf("%d\n%d", gcd, lcm);
	return 0;
}