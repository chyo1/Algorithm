#include <stdio.h>
int maze[1001][1001], D[1001][1001];
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int N, M;
	int i, j, sum = 0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &maze[i][j]);
		}
	}
	for (i = 1; i <= N; i++) {
		D[i][1] = maze[i][1] + D[i - 1][1];
		for (j = 2; j <= M; j++) {
			if (i == 1) D[1][j] = D[1][j - 1] + maze[1][j];
			D[i][j] = maze[i][j] + max(max(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]);
		}

	}
	printf("%d", D[N][M]);
	return 0;
}