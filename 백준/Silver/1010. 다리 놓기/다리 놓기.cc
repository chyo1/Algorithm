#include <stdio.h>
int cal[30][30];
void Pascal(int n, int m);
int main() {
	int T, i;
	int N, M;
	scanf("%d", &T);
	Pascal(30, 30);
	for (i = 0; i < T; i++) {
		int cnt = 0;
		scanf("%d %d", &N, &M); //N<=M
		printf("%d\n", cal[M][N]); // N C M
	}
	return 0;
}
void Pascal(int n, int m) {	
	cal[0][0] = cal[1][0] = cal[1][1] = 1;

	for (int i = 2; i < m; i++) {
		cal[i][0] = cal[i][i] = 1;
		for (int j = 1; j < i; j++) {
			cal[i][j] = cal[i - 1][j - 1] + cal[i - 1][j];
		}
	}
}