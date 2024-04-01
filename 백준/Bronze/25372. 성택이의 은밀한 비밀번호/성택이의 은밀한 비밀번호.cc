#include <stdio.h>
#include <string.h>
int main() {
	int T;
	char s[21];

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%s", s);
		if (strlen(s) < 6 || strlen(s) > 9) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}