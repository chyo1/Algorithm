#include <stdio.h>
int main() {
	int N, K, P;
	int i, j, cnt = 0, flag[1001] = { 0, };
	scanf("%d %d", &N, &K);
	for (i = 2; i <= N; i++) {
		if (!flag[i]) {
			P = i;
			for (j = P; j <= N; j += P) {
				if ((j%P == 0) && (!flag[j])) {
					flag[j]++;
					if (--K==0) {
						printf("%d", j);
						return 0;
					}
				}
			}
		}
	}
	printf("%d", N);
	return 0;
}