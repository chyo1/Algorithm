#include <stdio.h>
#include <string.h>
int main() {
	int alpha[26] = { 0, };
	char s[101];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) alpha[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) printf("%d ", alpha[i]);
	return 0;
}