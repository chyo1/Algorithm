#include <stdio.h>
int main() {
	int a1, a0, c, n0, p = 0;
	scanf("%d %d\n%d\n%d", &a1, &a0, &c, &n0);

	if (c - a1 > 0) {
		if ((c - a1)*n0 >= a0) p = 1;
	}
	else if (c - a1 == 0 && a0 <= 0) p = 1;
	printf("%d", p);
	return 0;
}