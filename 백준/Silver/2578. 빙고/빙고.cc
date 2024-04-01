#include <stdio.h>
int bingo[5][5], line = 0;
bool check[5][5];

void Is_bingo(int x, int y) {
	int i;

	// 가로
	for (i = 0; i < 5; i++) {
		if (!check[x][i]) break;
	}
	if (i == 5) line++;

	// 세로
	for (i = 0; i < 5; i++) {
		if (!check[i][y]) break;
	}
	if (i == 5) line++;

	// 왼쪽 대각선 방향 
	if (x == y) {
		for (i = 0; i < 5; i++) {
			if (!check[i][i]) break;
		}
		if (i == 5) line++;
	}
	

	// 오른쪽 대각선 방향 /
	if (x == (4 - y)) {
		for (i = 0; i < 5; i++) {
			if (!check[i][4 - i]) break;
		}
		if (i == 5) line++;
	}	
}

void Checking(int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == num) {
				check[i][j] = true;
				Is_bingo(i, j);
				return;
			}
		}
	}
}

int main() {
	int num, i;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) scanf("%d", &bingo[i][j]);
	}

	for (i = 1;; i++) {
		scanf("%d", &num);
		Checking(num);
		if (line >= 3) break;
	}

	printf("%d", i);
	return 0;
}