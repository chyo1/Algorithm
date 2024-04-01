#include <stdio.h>
int main() {
	int N, i;
	int cnt_A = 1, cnt_B = 0;
	scanf("%d", &N);
	int A, B;
	for (i = 0; i < N; i++) {
		A = cnt_A, B = cnt_B;
		cnt_B = A + B;
		cnt_A = B;
	}
	printf("%d %d", cnt_A, cnt_B);
	return 0;
}