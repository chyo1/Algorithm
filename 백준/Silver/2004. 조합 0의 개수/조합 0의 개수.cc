#include <stdio.h>

long int get_cnt(int N, int div) {
	long int cnt = 0;
	for (long int i = div; i <= N; i *= div) {
		cnt += N / i;
	}
	return cnt;
}
int main() {
	int N, M;
	long int cnt_2, cnt_5, cnt; // N이 2억일 경우 cnt_2 > 2억
	scanf("%d %d", &N, &M);

	cnt_2 = get_cnt(N, 2) - get_cnt(N - M, 2) - get_cnt(M, 2);
	cnt_5 = get_cnt(N, 5) - get_cnt(N - M, 5) - get_cnt(M, 5);

	cnt = cnt_2 > cnt_5 ? cnt_5 : cnt_2;
	printf("%ld", cnt);
	return 0;
}