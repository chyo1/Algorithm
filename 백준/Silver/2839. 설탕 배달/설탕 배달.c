#include <stdio.h>
int main() {
	int N, a, b = 0, sum;
	scanf("%d", &N); // N=5*a+3*b
	a = N / 5;
	while (1) {
		if (a < 0) {
			printf("-1");
			return 0;
		}
		sum = 5 * a + 3 * b;
		if (sum == N) break;
		else if (sum > N) a--, b = 0;
		else b++;
		
	}
	printf("%d", a + b);
	return 0;
}