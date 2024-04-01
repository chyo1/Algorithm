#include <stdio.h>
int main() {
	char word[101];
	int N, i, j, flag, cnt = 0, atoz[26] = { 0, };

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &word);

		j = 0;
		while (word[j] != NULL) {
			atoz[word[j] - 'a']++;
			if (atoz[word[j] - 'a'] > 1 && word[j] != word[j - 1]) break;
			j++;
		}
		if (word[j] == NULL) cnt++;

		for (j = 0; j < 26; j++) atoz[j] = 0;
	}
	printf("%d", cnt);
	return 0;
}