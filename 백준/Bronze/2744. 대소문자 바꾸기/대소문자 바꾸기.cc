#include <stdio.h>
#include <string.h>
int main() {
	char s[101];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if ('a' <= s[i] && s[i] <= 'z') printf("%c", s[i] - 'a' + 'A');
		else if ('A' <= s[i] && s[i] <= 'Z') printf("%c", s[i] - 'A' + 'a');
	}
	return 0;
}