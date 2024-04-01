#include <stdio.h>
int Fibo(int n);
int main() {
	int N;
	scanf("%d", &N);
	printf("%d", Fibo(N));
	return 0;
}
int Fibo(int n) {
	if (n == 0) return 0;
	else if (n == 1 || n == 2) return 1;
	return Fibo(n-1) + Fibo(n - 2);
}