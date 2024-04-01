#include <stdio.h>
int main() {
	float N, i, score, max = 0, sum = 0, avg;
	scanf("%f", &N);
	for (i = 0; i < N; i++) {
		scanf("%f", &score);
		sum += score;
		if (max < score) max = score;
	}
	printf("%f", (sum * 100) / (max*N));
}