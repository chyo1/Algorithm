#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

#define INF 100000000
int Min(int a, int b) { if (a < b) return a; return b; }
int main() {
	int N, M, a, b, c;
	int D[101][101];

	// init
	fill(D[0], D[101], INF);
	for (int i = 1; i <= 100; i++) D[i][i] = 0;

	// input
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		D[a][b] = Min(c, D[a][b]);
	}

	// floyd - warshall
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = Min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	// print
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[i][j] == INF) D[i][j] = 0;
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	return 0;
}