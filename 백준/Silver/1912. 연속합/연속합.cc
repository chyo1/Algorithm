#include <stdio.h>
int num[100001], DP[100001];
int MAX(int a, int b) { return a > b ? a : b; }
int main() {
	int n, i, max;

	scanf("%d", &n);
	for (i = 0; i < n; i++)	scanf("%d", &num[i]);

	max = DP[0] = num[0];
	for (i = 1; i < n; i++) {
		DP[i] = MAX(num[i], DP[i - 1] + num[i]);
		max = MAX(max, DP[i]);
	}
	printf("%d", max);
	return 0;
}