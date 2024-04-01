#include <stdio.h>
int main() {
	int N, i, num[100000], len_asc = 1, len_dsc = 1, max = 1;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &num[i]);
	for (i = 0; i < N - 1; i++) {
		if (num[i] < num[i + 1]) len_asc++, len_dsc = 1;
		else if (num[i] > num[i + 1]) len_dsc++, len_asc = 1;
		else len_asc++, len_dsc++;

		if (len_asc > max) max = len_asc;
		if (len_dsc > max) max = len_dsc;
	}
	printf("%d", max);
	return 0;
}