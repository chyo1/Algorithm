#include <stdio.h>
#include <string.h>
int main() {
	int T;
	char s[1001];
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%s", s);

		printf("%c%c\n", s[0], s[strlen(s) - 1]);
	}

	return 0;
}