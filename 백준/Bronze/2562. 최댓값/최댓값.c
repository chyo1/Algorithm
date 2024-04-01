#include <stdio.h>
int main() {
	int n, i, cnt, max = 0;

	for (i = 0; i < 9; i++) {
		scanf("%d", &n);
		if (max < n) max = n, cnt = i + 1;

	}
	printf("%d\n%d", max, cnt);
}