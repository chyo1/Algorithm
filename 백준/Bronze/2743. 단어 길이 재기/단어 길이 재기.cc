#include <stdio.h>
int main() {
	char s[101], i = 0;
	scanf("%s", s);
	while (s[i++] != NULL);
	printf("%d", i - 1);
	return 0;
}