#include <stdio.h>
bool map[100][100];
int main() {
	int N, garo = 0, sero = 0;
	char s[101];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &s);
		for (int j = 0; j < N; j++) {
			if (s[j] == 'X') map[i][j] = true;
		}
	}


	for (int i = 0; i < N; i++) {
		// 가로
		bool is_wall = true;
		for (int j = 0; j < N - 1; j++) {
			if (is_wall && !map[i][j] && !map[i][j + 1]) {
				garo++; is_wall = false;
			}
			if (map[i][j]) is_wall = true;
		}

		// 세로
		is_wall = true;
		for (int j = 0; j < N - 1; j++) {
			if (is_wall && !map[j][i] && !map[j + 1][i]) {
				sero++; is_wall = false;
			}
			if (map[j][i]) is_wall = true;
		}
	}

	printf("%d %d", garo, sero);
	return 0;
}