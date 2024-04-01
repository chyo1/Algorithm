#include <stdio.h>
int main() {
	int A, B;
	while (scanf("%d %d", &A, &B)!=EOF) {
		printf("%d\n", B / (A + 1));
	}

	return 0;
}