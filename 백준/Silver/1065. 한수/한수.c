#include <stdio.h>
int main() {
	int i, N, cnt = 99;
	scanf("%d", &N);
	if (N < 100) cnt = N;
	else {
		for (i = 100; i <= N; i++) {
			if (Han(i) == 1) cnt++;
		}
	}
	printf("%d", cnt);
}
int Han(int n) {
	int n_100, n_10, n_1;

	n_100 = n / 100;
	n_10 = n / 10 - n_100 * 10;
	n_1 = n % 10;
	if ((n_100 - n_10) == (n_10 - n_1)) return 1;

	return 0;
}