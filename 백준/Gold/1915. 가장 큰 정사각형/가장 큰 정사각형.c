#include<stdio.h>
char map[1001][1001];
int D[1001][1001];
int min(int a, int b) { return a < b ? a : b; }
int main() {
	char c;
	int n, m;
	int i, j, max = 0;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		scanf("%c", &c);
		for (j = 1; j <= m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '1') max = 1;
		}
	}

	for (i = 1; i <= n; i++) D[i][1] = map[i][1] - '0';
	for (j = 1; j <= m; j++) D[1][j] = map[1][j] - '0'; // 초기화

	for (i = 2; i <= n; i++) {
		for (j = 2; j <= m; j++) {
			if (map[i][j] == '0') D[i][j] = 0;
			else {
				D[i][j] = min(min(D[i][j - 1], D[i - 1][j - 1]), D[i - 1][j]) + 1;
				if (max < D[i][j]) max = D[i][j];
			}
		}
	}

	printf("%d", max*max);
	return 0;
}