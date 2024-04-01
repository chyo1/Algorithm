#include <stdio.h>
long long Get_Fac(int n) {
	if (n == 0) return 1;
	return n * Get_Fac(n - 1);
}
int main() {
	int N;
	scanf("%d", &N);
	printf("%lld", Get_Fac(N));
	return 0;
}