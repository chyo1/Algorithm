#include <stdio.h>
int main() {
	int i, alphabet, loc[26];
	char word[101];
	scanf("%s", &word);
	for (i = 0; i < 26; i++) loc[i] = -1;

	i = 0;
	while (word[i] != NULL) {
		alphabet = word[i] - 97;
		if (loc[alphabet] == -1) loc[alphabet] = i;
		i++;
	}

	for (i = 0; i < 26; i++) printf("%d ", loc[i]);
}