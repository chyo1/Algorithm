#include <stdio.h>
char S[6570][6570];
void Blank(int a, int b, int N) {
	for (int i = a; i < a + N; i++) {
		for (int j = b; j < b + N; j++) S[i][j] = ' ';
	}
}
void Star(int a, int b, int N) {
	if (N > 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) Blank(a + i * N / 3, b + j * N / 3, N / 3);
				else Star(a + i * N / 3, b + j * N / 3, N / 3);
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) S[a][b + i] = '*';
		S[a + 1][b + 1] = ' ';
		S[a + 1][b] = S[a + 1][b + 2] = '*';
		for (int i = 0; i < 3; i++) S[a + 2][b + i] = '*';
	}
}
int main() {
	int N;
	scanf("%d", &N);
	Star(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%c", S[i][j]);
		printf("\n");
	}
	return 0;
}