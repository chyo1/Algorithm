#include <stdio.h>
#include <climits>
int DP[100001];
int s[320];
int min(int a, int b) { return a < b ? a : b; }
int main() {
	int N, i = 1;
	scanf("%d", &N);

	while (i*i <= N) {
		DP[i*i] = 1;
		s[i] = i * i;
		i++;
	}
	int k = 0;
	for (i = 1; i <= N; i++) {
		if (DP[i] == 1) k++;
		else {
			DP[i] = INT_MAX;
			for (int j = 1; j <= k; j++)
				DP[i] = min(DP[s[j]] + DP[i - s[j]], DP[i]);
		}
	}
	printf("%d", DP[N]);
	return 0;
}