#include <stdio.h>
int main() {
	int N, x, y;
	int max_x = -10001, min_x = 10001, max_y = -10001, min_y = 10001;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		if (x < min_x) min_x = x;
		if (x > max_x) max_x = x;
		if (y < min_y) min_y = y;
		if (y > max_y) max_y = y;

	}
	printf("%u", (max_x - min_x)*(max_y - min_y));

	return 0;
}