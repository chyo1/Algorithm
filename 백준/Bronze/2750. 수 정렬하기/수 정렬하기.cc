#include <stdio.h>
#include <algorithm>

int num[1000];
int cmp(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num[i]);
	qsort(num, N, sizeof(int), cmp);
	for (int i = 0; i < N; i++) printf("%d ", num[i]);
	return 0;
}
