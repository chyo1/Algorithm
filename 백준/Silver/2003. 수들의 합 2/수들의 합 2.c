#include <stdio.h>
int main() {
	int A[10000];
	unsigned int M, sum = 0;
	int N, i, j = 0, cnt = 0;

	scanf("%d%u", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &A[i]); //  입력

	for (i = 0; i < N; i++) {

		sum += A[i];

		if (sum > M) {
			while (sum > M)	sum -= A[j++];
		}
		if (sum == M) {
			cnt++;
			sum -= A[j++];
		}
	}

	printf("%d", cnt);
	return 0;
}
