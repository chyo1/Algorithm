#include <stdio.h>

int P[15][15];
void get_P();
int main() {
	int n, k, T;

	scanf("%d", &T);
	get_P();
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &k, &n);
		printf("%d\n", P[k][n]);
	}
	return 0;
}
void get_P() {
	int i, j, k;

	// 0 floor
	for (j = 1; j <= 14; j++) P[0][j] = j;

	// 1~14 floor
	for (i = 1; i <= 14; i++) {
		P[i][1] = 1;
		for (j = 2; j <= 14; j++) {
			P[i][j] = P[i][j - 1] + P[i - 1][j];
		}
	}
}