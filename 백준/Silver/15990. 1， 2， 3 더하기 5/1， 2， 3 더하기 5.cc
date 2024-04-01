#include <stdio.h>
unsigned int DP[100001] = { 0,1,1,3,3 };
unsigned int D1[100001] = { 0,1,0,1,2 };
unsigned int D2[100001] = { 0,0,1,1,0 };
unsigned int D3[100001] = { 0,0,0,1,1 };
int main() {
	int T, n;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);

		for (int i = 4; i <= n; i++) {
			if (DP[i]) continue;
			D1[i] = (D2[i - 1] + D3[i - 1]) %1000000009;
			D2[i] = (D1[i - 2] + D3[i - 2]) % 1000000009;
			D3[i] = (D1[i - 3] + D2[i - 3]) % 1000000009;
			DP[i] = (D1[i] + D2[i] + D3[i]) % 1000000009;
		}
		printf("%u\n", DP[n]);
	}
	return 0;
}