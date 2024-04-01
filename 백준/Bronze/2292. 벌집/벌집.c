#include <stdio.h>
int main() {
	int N, i = 0, sum = 2;
	scanf("%d", &N);

	while (sum <= N) {
		i++;
		sum += 6 * i;
	}

	printf("%d", i + 1);
	return 0;
}