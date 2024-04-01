#include <stdio.h>
int min(int a, int b) {
	if (a < b) return a;
	return b;
}
int main() {
	int c[1000][3];
	int N, m;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
	}
	for (int i = 1; i < N; i++) {
		c[i][0] += min(c[i - 1][1], c[i - 1][2]);
		c[i][1] += min(c[i - 1][0], c[i - 1][2]);
		c[i][2] += min(c[i - 1][0], c[i - 1][1]);
	}
	m = min(c[N - 1][0], c[N - 1][1]);
	m = min(m, c[N - 1][2]);

	printf("%d", m);
	return 0;
}