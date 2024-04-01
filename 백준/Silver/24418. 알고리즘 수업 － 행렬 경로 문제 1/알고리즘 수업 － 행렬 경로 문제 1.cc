#include <stdio.h>
int cnt1 = 0, cnt2 = 0;
int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int matrix_path_rec(int m[][15], int i, int j) {
	// (1, 1)에서 (i, j)에 이르는 최고 점수를 구한다.
	if (i == 0 || j == 0) {
		cnt1++;
		return 0; // 코드1
	}
	else return (m[i][j] + (max(matrix_path_rec(m, i - 1, j), matrix_path_rec(m, i, j - 1))));
}
int matrix_path(int m[][15], int n) {
	// (1, 1)에서 (n, n)에 이르는 최고 점수를 구한다.
	return matrix_path_rec(m, n, n);
}

int matrix_path_dp(int m[][15], int n) {
	int d[16][16];
	for (int i = 0; i <= n; i++) d[i][0] = 0;
	for (int j = 1; j <= n; j++) d[0][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt2++;
			d[i][j] = m[i][j] + max(d[i][j], d[i][j - 1]);
		}
	}
	return d[n][n];
}
int main() {
	int n, m[15][15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &m[i][j]);
	}
	matrix_path(m, n);
	matrix_path_dp(m, n);
	printf("%d %d", cnt1, cnt2);
	return 0;
}