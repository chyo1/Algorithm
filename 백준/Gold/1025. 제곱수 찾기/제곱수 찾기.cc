#include <stdio.h>
#include <math.h>


int map[10][10];
int max = -1;
int N, M;

void Find(int sx, int sy, int i, int j, int num) {
	if (sx < 0 || sy < 0 || sx >= N || sy >= M) return;

	num = num * 10 + map[sx][sy];
	int half = sqrt(num);
	if (half*half == num && max < num) max = num;

	return Find(sx + i, sy + j, i, j, num);
}

void Start() {
	int mx[8] = { -1,-1,-1,0,0,1,1,1 };
	int my[8] = { -1,0,1,-1,1,-1,0,1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { // starting point
			for (int o = 0; o < 8; o++) { // direction

				for (int k = 1; k <= 9; k++) {
					for (int l = 1; l <= 9; l++) { // jumping gap
						Find(i, j, k*mx[o], l*my[o], 0);
					}
				}
			}
		}
	}
}

int main() {
	char s[10];

	// input
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	Start();
	printf("%d", max);

	return 0;
}