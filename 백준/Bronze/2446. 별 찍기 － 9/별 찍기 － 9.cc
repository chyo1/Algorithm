#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	for (int i = N; i > 0; i--) {
		for (int j = N; j > i; j--) printf(" ");
		for (int j = 0; j < 2 * i - 1; j++) printf("*");
		printf("\n");
	}
	for (int i = 1; i < N; i++) {
		for (int j = N - 1 - i; j > 0; j--) printf(" ");
		for (int j = 0; j < 2 * i + 1; j++) printf("*");
		printf("\n");
	}
	return 0;
}