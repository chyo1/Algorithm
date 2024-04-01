#include <stdio.h>

int main() {
	int N, i, num, div = 2;
	scanf("%d", &N);

	while (N != 1) {
		if (N%div==0) {
			printf("%d\n", div);
			N /= div;
		}
		else div++;
	}
	return 0;
}