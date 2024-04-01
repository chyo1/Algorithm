#include <stdio.h>
#include <string.h>
int main() {
	char word[6];
	int s, e;
	bool Is_Pal;
	while (1) {
		scanf("%s", word);
		if (word[0] == '0') break;

		s = e = 0; Is_Pal = true;
		while (word[++e] != NULL);
		e--;
		while (s < e) {
			if (word[s++] != word[e--]) {
				Is_Pal = false;
				break;
			}
		}
		if (Is_Pal) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}