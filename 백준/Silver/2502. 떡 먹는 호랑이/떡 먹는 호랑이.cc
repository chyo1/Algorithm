#include <stdio.h>
using namespace std;

int DP[31][2];

int main() {
	int D, K, A = 1, B = 0;
	scanf("%d %d", &D, &K);

	DP[1][0] = DP[2][1] = 1;
	for (int i = 3; i <= 30; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
		DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
	}
	while (1) {
		B = K - DP[D][0] * A;
		if (B%DP[D][1] == 0) {
			B /= DP[D][1];
			if (B > A) break;
		}
		A++;
	}
	printf("%d\n%d", A, B);
	return 0;
}