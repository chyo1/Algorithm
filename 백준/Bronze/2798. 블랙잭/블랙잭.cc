#include <stdio.h>
#include <cmath>
int main() {
	int N, M;
	int i, j, k, sum, num[100];
	int min = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &num[i]);

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			for (k = j + 1; k < N; k++) {
				sum = num[i] + num[j] + num[k];
				if (sum <= M && M - sum < M - min) min = sum;
			}
		}
	}
	printf("%d", min);
	return 0;
}