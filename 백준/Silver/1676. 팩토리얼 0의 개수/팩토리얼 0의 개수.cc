#include <stdio.h>
int main() {
	int N, n;
	int cnt_2 = 0, cnt_5 = 0, cnt;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		n = i;
		while (n % 2 == 0) {
			n /= 2;
			cnt_2++;
		}
		while (n % 5 == 0) {
			n /= 5;
			cnt_5++;
		}
	}
	cnt = cnt_2 > cnt_5 ? cnt_5 : cnt_2;
	printf("%d", cnt);
	return 0;
}