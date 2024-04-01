#include <stdio.h>
long long Get_max(int S, int K) {
	int div[20] = { 0, }, sum = 0, loc = 0;
	long long ans = 1;

	for (int i = 0; i < K; i++) {
		div[i] = S / K;
		sum += div[i];
	}

	while (sum != S) {
		div[loc++]++;
		sum++;
	}
	for (int i = 0; i < K; i++) ans *= div[i];

	return ans;
}

int main() {
	int S, K;
	scanf("%d %d", &S, &K);
	printf("%lld", Get_max(S,K));
	return 0;
}