#include <stdio.h>
int main() {
	int A,B,i;
	while (1) {
		scanf("%d%d", &A, &B);
		if (!A && !B) break;
		printf("%d\n", A + B);
	}
}