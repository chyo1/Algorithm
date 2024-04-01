#include <stdio.h>
int main() {
	int N, i, sum = 0;
	char num[101];
	scanf("%d", &N);
	scanf("%s", &num);
	for (i = 0; i < N; i++)
		sum += num[i] - 48;

	printf("%d", sum);
}