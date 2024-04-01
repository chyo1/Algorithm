#include <stdio.h>
int w[21][21][21];
bool visit[21][21][21];
int Get_W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return Get_W(20, 20, 20);

	if (visit[a][b][c]) return w[a][b][c];
	visit[a][b][c] = true;

	if (a < b&&b < c)
		w[a][b][c] = Get_W(a, b, c - 1) + Get_W(a, b - 1, c - 1) - Get_W(a, b - 1, c);
	else
		w[a][b][c] = Get_W(a - 1, b, c) + Get_W(a - 1, b - 1, c) + Get_W(a - 1, b, c - 1) - Get_W(a - 1, b - 1, c - 1);

	return w[a][b][c];
}

int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
				visit[0][i][j] = visit[i][0][j] = visit[i][j][0] = true;
			}
		}

		printf("w(%d, %d, %d) = %d\n", a, b, c, Get_W(a, b, c));
	}
	return 0;
}