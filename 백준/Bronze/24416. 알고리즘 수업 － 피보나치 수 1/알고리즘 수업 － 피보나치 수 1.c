#include <stdio.h>
int fib(int n) {
	int cnt = 1;
	if (n == 1 || n == 2) return cnt++;
	else return (fib(n - 1) + fib(n - 2));
}
int fibonacci(int n) {
	int cnt = 0;
	int f0 = 0, f1 = 1, f2 = 1;
	if (n == 1 || n == 2) return 1;
	else {
		for (int i = 3; i <= n; i++) {
			f2 = f0 + f1;
			f0 = f1, f1 = f2;
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int n;
	scanf("%d", &n);

	printf("%d ", fib(n));
	printf("%d", fibonacci(n));
	return 0;
}