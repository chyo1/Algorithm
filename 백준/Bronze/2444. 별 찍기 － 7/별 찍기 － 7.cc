#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int b = N; b > i; b--) printf(" ");
		for (int s = 0; s < 2 * i - 1; s++) printf("*");
		printf("\n");
	}
	for (int i = N - 1; i > 0; i--) {
		for (int b = N; b > i; b--) printf(" ");
		for (int s = 0; s < 2 * i - 1; s++) printf("*");
		printf("\n");
	}
	return 0;
}