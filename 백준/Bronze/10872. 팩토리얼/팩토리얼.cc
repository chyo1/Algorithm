#include <stdio.h>
int Factorial(int n);
int main() {
	int N;
	scanf("%d", &N);
	printf("%d",Factorial(N));
	return 0;
}
int Factorial(int n) {
	if (n == 0) return 1;
	return n * Factorial(n - 1);
}