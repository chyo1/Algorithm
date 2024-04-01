#include <stdio.h>
#include <string.h>

char s[100001], rev[100001];
int main() {
	/*string S;
	getline(cin, S);*/
	

	scanf("%[^\n]s", s);

	int loc = 0, i = 0, len = strlen(s);
	while (i < len) {

		if (s[i] == '<') {

			rev[loc] = NULL;
			while (loc > 0) printf("%c", rev[--loc]);

			// < ... >
			while (s[i] != '>') printf("%c", s[i++]);
			printf("%c", s[i++]);
		}

		else if (s[i] == ' ') {

			rev[loc] = NULL;
			while (loc > 0) printf("%c", rev[--loc]);
			printf(" ");

			i++;
		}

		else rev[loc++] = s[i++];
	}

	rev[loc] = NULL;
	while (loc > 0) printf("%c", rev[--loc]);

	return 0;
}