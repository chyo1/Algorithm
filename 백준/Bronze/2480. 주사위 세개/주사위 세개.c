#include <stdio.h>
int main() {
	int n1, n2, n3, max;
	scanf("%d%d%d", &n1, &n2, &n3);
	if (n1 == n2 && n2 == n3) printf("%d", 10000 + 1000 * n1);
	if (n1 != n2 && n2 != n3 && n1 != n3) {
		max = n1;
		if (n1 < n2) max = n2;
		if (max < n3) max = n3;
		printf("%d", max * 100);
	}
	if ((n1 == n2 && n2 != n3)|| (n1 == n3 && n2 != n3)) printf("%d", 1000 + n1 * 100);
	else if (n2 == n3 && n1 != n2) printf("%d", 1000 + n2 * 100);
}