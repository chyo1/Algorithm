#include <stdio.h>
int num[1001][1001];
void Com(int n) {
	int i, j;
	num[0][0] = num[1][0] = num[1][1] = 1;
	for (i = 2; i <= n; i++) {
		num[i][0] = num[i][i] = 1;
		for (j = 1; j < i; j++) {
			num[i][j] = (num[i - 1][j - 1] + num[i - 1][j]) % 10007;
		}
	}
}
int main() {
	int n;
	int i, j, sum = 0;
	scanf("%d", &n);
	Com(n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (i + 2 * j == n) {
				sum += num[i + j][i];
				sum %= 10007;
			}
		}
	}
	printf("%d", sum);
	return 0;
}