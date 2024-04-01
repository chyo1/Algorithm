#include <stdio.h>
int main() {
	int T, A, B, C;
	scanf("%d", &T);

	A = T / 300;
	T -= A * 300;

	B = T / 60;
	T -= B * 60;

	C = T / 10;

	if (T % 10 != 0) printf("-1");
	else printf("%d %d %d", A, B, C);
	return 0;
}