#include <stdio.h>

int main() {
	int n, cnt = 0, i = 0;
	int change[6] = { 500,100,50,10,5,1 };
	scanf("%d", &n);

	n = 1000 - n;
	while (n != 0) {
		cnt += n / change[i];
		n %= change[i++];
	}
	printf("%d", cnt);
	return 0;
}