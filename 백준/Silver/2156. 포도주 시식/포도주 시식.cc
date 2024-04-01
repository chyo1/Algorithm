#include <stdio.h>
int Max(int a, int b) {
	if (a > b) return a;
	return b;
}
int main() {
	int n;
	int wine[10000], DP[10000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &wine[i]);

	DP[0] = wine[0], DP[1] = wine[0] + wine[1];
	DP[2] = Max(DP[1], Max(wine[1] + wine[2], wine[0] + wine[2]));

	for (int i = 3; i < n; i++) {
		DP[i] = Max(DP[i - 1], Max(DP[i - 3] + wine[i - 1] + wine[i], DP[i - 2] + wine[i]));
	}
	printf("%d", DP[n - 1]);
	return 0;
}