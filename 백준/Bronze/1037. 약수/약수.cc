#include <stdio.h>
#include <limits.h>
int main() {
	int cnt, num;
	int i, min = INT_MAX, max = 0;
	scanf("%d", &cnt);
	if (cnt == 1) {
		scanf("%d", &num);
		printf("%d", num*num);
	}
	else {
		for (i = 0; i < cnt; i++) {
			scanf("%d", &num);
			if (min > num) min = num;
			if (max < num) max = num;
		}
		printf("%d", min*max);
	}
	return 0;
}