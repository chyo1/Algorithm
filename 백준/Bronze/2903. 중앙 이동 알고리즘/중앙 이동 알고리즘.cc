#include <stdio.h>
#include <math.h>

int main() {
	int N, cnt;
	scanf("%d", &N);

	cnt = pow(2, N);
	printf("%d", (cnt + 1)*(cnt + 1));
	return 0;
}