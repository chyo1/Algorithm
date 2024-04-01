#include <stdio.h>
int main() {
	int len = -1;
	char s[101];

	scanf("%s", s);

	while (s[++len] != NULL);

	for (int i = 0; i < len; i += 10) {
		for (int j = i; j < i + 10 && j < len; j++) printf("%c", s[j]);
		printf("\n");
	}

	return 0;
}