#include <stdio.h>
int main() {
	int N, n1, n2, cnt=0;
	scanf("%d %d %d", &N, &n1, &n2);
	while (n1 != n2) {
		if (!n1 || !n2) {
			printf("-1");
			return 0;
		}
		if (n1 % 2) n1 = (n1 + 2) / 2;
		else n1 /= 2;

		if (n2 % 2) n2 = (n2 + 2) / 2;
		else n2 /= 2;
		
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}