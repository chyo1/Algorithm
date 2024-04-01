#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
stack <char> S;

bool Bal(char s[], int size);
void Clear();

int main() {
	char s[101];
	int res;
	while (1) {
		scanf("%[^\n]s", &s);
		if (strcmp(s, ".\0") == 0) break;

		res = Bal(s, strlen(s));

		if (res) printf("yes\n");
		else printf("no\n");

		scanf("%c", &s);
		Clear();
	}
	return 0;
}
bool Bal(char s[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (s[i] == '(' || s[i] == '[') S.push(s[i]);

		else if (s[i] == ')') {
			if (S.empty()) return false;
			else {
				if (S.top() == '(') S.pop();
				else return false;
			}
		}

		else if (s[i] == ']') {
			if (S.empty()) return false;
			else {
				if (S.top() == '[') S.pop();
				else return false;
			}
		}
	}
	if (!S.empty()) return false;
	return true;
}
void Clear() {
	while (!S.empty()) S.pop();
}