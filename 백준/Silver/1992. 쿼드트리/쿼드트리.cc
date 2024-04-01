#include <stdio.h>
bool T[64][64];
void Print(int sx, int sy, int n) {
	bool compare = T[sx][sy];
	for (int i = sx; i < sx + n; i++) {
		for (int j = sy; j < sy + n; j++) {
			
			if (T[i][j] != compare) {
				n /= 2;
				printf("(");
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						Print(sx + k * n, sy + l * n, n);
					}
				}
				printf(")");
				return;
			}
		}
	}

	if (compare) printf("1");
	else printf("0");
	return;
}

int main() {
	int N;
	char s[65];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < N; j++) T[i][j] = s[j] - '0';
	}
	Print(0, 0, N);
	return 0;
}