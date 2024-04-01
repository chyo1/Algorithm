#include <stdio.h>
int Fn[1000001] = { 0,1,1 };
int main() {
	int R, C, W;
	int i, j, sum;
	int pas[31][31];
	scanf("%d %d %d", &R, &C, &W);

	pas[0][0] = pas[1][0] = pas[1][1] = 1;
	for (i = 2; i <= 30; i++) {
		pas[i][0] = pas[i][i] = 1;
		for (j = 1; j < i; j++)
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
	}
	sum = pas[R - 1][C - 1];
	for (i = 1; i < W; i++) {
		for (j = 0; j <= i; j++) {
			sum += pas[R + i - 1][C + j - 1];
		}
	}
	printf("%d", sum);
	return 0;
}