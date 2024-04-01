#include <stdio.h>
int main() {
	int T, N, i, j, cnt;
	double avg, sum, score[1000];
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		sum = 0;
		for (j = 0; j < N; j++) {
			scanf("%lf", &score[j]);
			sum += score[j];
		}
		avg = sum / N;

		cnt = 0;
		for (j = 0; j < N; j++) {
			if (score[j] > avg) cnt++;
		}
		printf("%.3f%%\n", (double) cnt * 100 / N);
	}
	return 0;
}