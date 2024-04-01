#include <stdio.h>
int main() {
	int d, n, cnt = 0;
	scanf("%d", &d);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		if (n % 10 == d) cnt++;
	}
	printf("%d", cnt);
	return 0;
}