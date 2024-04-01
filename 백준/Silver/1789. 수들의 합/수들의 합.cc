#include <stdio.h>

int main() {
	unsigned long long int S, sum = 0, N = 0;

	// input
	scanf("%llu", &S);
	
	while (sum < S) sum += ++N;

	if (sum > S) N--;

	// print
	printf("%llu", N);
	return 0;
}