#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int N, i, j, Max = 0;
	int T[16] = { 0, }, P[16] = { 0, };

	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d %d", &T[i], &P[i]);

	for (i = N - 1; i >= 0; i--) {
		if (i + T[i] > N)	P[i] = P[i + 1];
		else P[i] = max(P[i + 1], P[i] + P[i + T[i]]);
	}
	printf("%d", P[0]);
	return 0;
}