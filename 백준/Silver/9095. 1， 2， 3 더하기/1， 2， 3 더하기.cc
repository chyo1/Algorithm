#include <stdio.h>
int fac[12] = { 1, };

void Factorial();
int sum123(int);
int main() {
	int T, n, i;
	scanf("%d", &T);
	Factorial();
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%d\n", sum123(n));
	}
	return 0;
}
void Factorial() {
	int i;
	for (i = 1; i <= 11; i++) {
		fac[i] = fac[i - 1] * i;
	}
}
int sum123(int n) {
	int i, j, cnt_1; // 2, 3의 갯수
	int sum = 0;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			if (2 * i + 3 * j <= n) {
				cnt_1 = n - (2 * i + 3 * j);
				sum += fac[cnt_1 + i + j] / (fac[i] * fac[j] * fac[cnt_1]);
			}
		}
	}
	return sum;
}