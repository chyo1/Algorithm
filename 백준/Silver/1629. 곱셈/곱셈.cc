#include <stdio.h>
int main() {
	int B, C;
	long long int A, sum = 1;

	scanf("%d %d %d", &A, &B, &C);
	while (B) {
		if (B & 1) sum = (sum* A) % C;
		A = (A*A) % C;
		B = B >> 1;
	}

	printf("%lld", sum);
	return 0;
}