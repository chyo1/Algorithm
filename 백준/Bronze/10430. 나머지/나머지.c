#include <stdio.h>
int main() {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	printf("%d\n%d\n", (A + B) % C, ((A%C) + (B%C)) % C);
	printf("%d\n%d", (A*B) % C, ((A%C) * (B%C)) % C);
	return 0;
}