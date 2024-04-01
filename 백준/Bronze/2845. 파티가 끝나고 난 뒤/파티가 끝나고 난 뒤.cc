#include <stdio.h>
int main() {
	int L, P;
	scanf("%d %d", &L, &P);
	P *= L;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &L);
		printf("%d ", L - P);
	}
	return 0;
}