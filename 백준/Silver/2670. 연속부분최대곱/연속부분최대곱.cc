#include <stdio.h>
int main() {
	int N, i;
	double arr[10000], DP[10000], max = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lf", &arr[i]);
	DP[0] = arr[0];
	for (i = 1; i < N; i++) {
		DP[i] = DP[i - 1] * arr[i] > arr[i] ? DP[i - 1] * arr[i] : arr[i];
		if (max < DP[i]) max = DP[i];
	}
	printf("%.3f", max);
	return 0;
}