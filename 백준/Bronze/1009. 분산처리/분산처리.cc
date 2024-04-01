#include <stdio.h>
int main() {
	int T, t, i;
	int a, b, N[10];
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d %d", &a, &b);
		N[0] = a % 10;
		i = 1;
		while (1) {
			N[i] = (N[i - 1] * a) % 10;
			if (N[i] == N[0]) break;
			i++;
		}
		int ans = b % i - 1;
		if (ans == -1) ans = i - 1;
		if (!N[ans]) N[ans] = 10;
		printf("%d\n", N[ans]);
	}

	return 0;
}