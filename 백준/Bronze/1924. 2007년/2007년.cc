#include <stdio.h>
int main() {
	int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	char Week[7][4] = { "SUN", "MON","TUE", "WED", "THU", "FRI", "SAT"};
	int x, y, d = 0;

	scanf("%d %d", &x, &y);

	for (int i = 1; i < x; i++) d += Month[i];
	d += y;

	printf("%s", Week[d % 7]);

	return 0;
}