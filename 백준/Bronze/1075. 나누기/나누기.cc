#include <stdio.h>
int main() {
	int N, F, start, i;
	scanf("%d %d", &N, &F);
	start = (N / 100) * 100;
	for (i = 0; i < 100; i++) {
		if ((start + i) % F == 0) break;
	}
	printf("%02d", (start + i) % 100);
	return 0;
}