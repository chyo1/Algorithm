#include <stdio.h>
int main() {
	int N;
	int a, b;
	scanf("%d", &N);

	a = N - N * 0.22;
	b = N - N * 0.044;

	printf("%d %d", a, b);
}