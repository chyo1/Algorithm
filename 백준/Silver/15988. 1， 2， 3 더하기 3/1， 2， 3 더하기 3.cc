#include <stdio.h>
long long int DP[1000001] = { 0,1,2,4,7 };
int main() {
	int T, n;
	scanf("%d", &T);
	for (int i = 5; i < 1000001; i++)
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % 1000000009;
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%lld\n", DP[n]);
	}
	return 0;
}