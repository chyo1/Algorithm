#include <stdio.h>
int main() {
	char word[101];
	int i = 0, cnt = 0;
	scanf("%s", &word);
	while (word[i] != NULL) {
		if (word[i] == 'c') {
			if (word[i + 1] == '=') i++;
			else if (word[i + 1] == '-') i++;
		}
		else if (word[i] == 'd') {
			if (word[i + 1] == '-') i++;
			else if (word[i + 1] == 'z'&& word[i + 2] == '=') i = i + 2;
		}
		else if (word[i] == 'l' || word[i]=='n') {
			if (word[i + 1] == 'j') i++;
		}
		else if (word[i] == 's' || word[i] == 'z') {
			if (word[i + 1] == '=') i++;
		}
		cnt++;
		i++;
	}
	printf("%d", cnt);
	return 0;
}