#include <stdio.h>

int main() {
	int M, F;
	while (1) {
		scanf("%d %d", &M, &F);
		if (!M && !F) break;
		else printf("%d\n", M + F);
	}
	return 0;
}