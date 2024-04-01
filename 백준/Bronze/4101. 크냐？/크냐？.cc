#include <stdio.h>
int main() {
	int A, B;
	while (1) {
		scanf("%d %d", &A, &B);
		if (!A && !B) break;

		if (A > B) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}