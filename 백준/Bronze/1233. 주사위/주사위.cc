#include <stdio.h>
int main() {
	int s1, s2, s3, max = 0, max_i = 0;
	int cnt[81] = { 0, };
	scanf("%d %d %d", &s1, &s2, &s3);
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				cnt[i + j + k]++;
			}
		}
	}
	for (int i = 1; i <= s1 + s2 + s3; i++) {
		if (max < cnt[i]) max = cnt[i], max_i = i;
	}
	printf("%d", max_i);
	return 0;
}