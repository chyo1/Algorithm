#include <stdio.h>
int main() {
	int X, stick = 64, sum = 0, cnt = 0;
	scanf("%d", &X);
	while (sum != X) {
		if (stick == X) {
			cnt = 1;
			break;
		}
		stick = stick >> 1;
		if (stick + sum <= X) {
			sum += stick;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}