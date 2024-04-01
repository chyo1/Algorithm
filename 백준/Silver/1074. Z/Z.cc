#include <stdio.h>
#include <math.h>
int N, r, c;
int cnt = 0;
bool print = false;
void D(int N, int a, int b) {
	int k1 = a + pow(2, N) - 1, k2 = b + pow(2, N) - 1;
	if (a + pow(2, N) - 1 < r || b + pow(2, N) - 1 < c) {
		cnt += pow(4, N);
		return;
	}

	if (N > 1) {
		int plus = pow(2, N - 1);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				D(N - 1, a + plus * i, b + plus * j);
				if (print) return;
			}
		}
	}
	else {
		for (int i = a; i < a + 2; i++) {
			for (int j = b; j < b + 2; j++) {
				if (i == r && j == c) {
					printf("%d", cnt);
					print = true;
					return;
				}
				cnt++;
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &r, &c);
	D(N, 0, 0);
	return 0;
}