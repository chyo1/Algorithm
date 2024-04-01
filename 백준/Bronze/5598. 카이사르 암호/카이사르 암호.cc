#include <stdio.h>

int main() {
	char s[1001];
	char change[27] = "XYZABCDEFGHIJKLMNOPQRSTUVW";
	scanf("%s", &s);

	int i = 0;
	while (s[i] != NULL) {
		printf("%c", change[s[i++]-'A']);
	}
	return 0;
}