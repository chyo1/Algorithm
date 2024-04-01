#include <stdio.h>
int main() {
	long long int P[101] = { 0,1,1,1,2,2,3 };
	int N, T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 7; i <= N; i++) P[i] = P[i - 1] + P[i - 5];
		printf("%lld\n", P[N]);
	}
	return 0;
}