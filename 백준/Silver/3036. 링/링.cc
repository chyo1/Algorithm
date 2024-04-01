#include <stdio.h>
int get_gcd(int a, int b) {
	if (!b) return a;
	return get_gcd(b, a%b);
}
int main() {
	int N, div, r, gcd;
	scanf("%d", &N);
	scanf("%d", &div); // 1st ring
	for (int i = 1; i < N; i++) {
		scanf("%d", &r);
		gcd = get_gcd(div, r);
		printf("%d/%d\n", div / gcd, r / gcd);
	}
	return 0;
}