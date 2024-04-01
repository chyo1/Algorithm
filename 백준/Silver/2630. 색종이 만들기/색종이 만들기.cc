#include <stdio.h>

bool map[128][128];
int white, blue;

bool Is_same(int x, int y, int N) {
	int value = map[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (value != map[i][j]) return false;
		}
	}
	return true;
}
void Cut(int x, int y, int N) {
	if (!Is_same(x, y, N)) {
		for (int i = x; i < x + N; i = i + N / 2) {
			for (int j = y; j < y + N; j = j + N / 2) {
				Cut(i, j, N / 2);
			}
		}
	}
	else {
		if (map[x][y]) blue++;
		else white++;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
	}
	Cut(0, 0, N);

	printf("%d\n%d", white, blue);
	return 0;
}