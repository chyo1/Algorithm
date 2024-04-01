#include <stdio.h>
#include <algorithm>
int cnt[10001];
int main() {
	int N;
	int n, i, j, num, c = 0;
	scanf("%d", &N);
	for (n = 0; n < N; n++) {
		scanf("%d", &num);
		cnt[num]++;
	}

	for (i = 1; i < 10001; i++) {
		if (!cnt[i]) continue;
		for (j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
			c++;
		}
		if (c == N) break;
	}
	return 0;
}