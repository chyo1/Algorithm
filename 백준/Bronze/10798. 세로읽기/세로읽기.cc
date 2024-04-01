#include <stdio.h>
int main() {
	char s[5][16] = { NULL, };
	for (int i = 0; i < 5; i++) scanf("%s", s[i]);

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[j][i] != NULL) printf("%c",s[j][i]);
		}
	}
	return 0;
}