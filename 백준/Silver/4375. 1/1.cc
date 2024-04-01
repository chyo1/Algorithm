#include <stdio.h>
int main() {
	int n;
	int num = 1, p = 1;
	while (1) {
		if (scanf("%d", &n) == EOF) break;
		
		while (num%n != 0) {
			num = num * 10 + 1;
			p++;
			num %= n;
		}
		printf("%d\n", p);

		p = num = 1;
	}
	return 0;
}