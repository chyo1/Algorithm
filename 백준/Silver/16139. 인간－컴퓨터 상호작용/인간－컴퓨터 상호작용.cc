#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> s[26];
string S;
void Sum() {
	int i, j, alpha[26] = { 0, };
	for (j = 0; j < 26; j++) s[j].push_back(alpha[j]);
	for (i = 0; i < S.length(); i++) {
		alpha[S[i] - 'a']++;

		for (j = 0; j < 26; j++) s[j].push_back(alpha[j]);
	}
}
int main() {
	int q, l, r;
	char c;

	cin >> S >> q;
	Sum();

	for (int i = 0; i < q; i++) {
		scanf("%c", &c); // \n
		scanf("%c %d %d", &c, &l, &r);
		printf("%d\n", s[c - 'a'][r + 1] - s[c - 'a'][l]);
	}
	return 0;
}