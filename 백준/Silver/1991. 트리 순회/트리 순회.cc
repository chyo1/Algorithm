#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

vector <pair<char, char>> V[26];

void Preorder(int root) {
	char l = V[root][0].first, r = V[root][0].second;

	printf("%c", root + 'A');
	if (isalpha(l)) Preorder(l - 'A');
	if (isalpha(r)) Preorder(r - 'A');
}
void Inorder(int root) {
	char l = V[root][0].first, r = V[root][0].second;

	if (isalpha(l)) Inorder(l - 'A');
	printf("%c", root + 'A');
	if (isalpha(r)) Inorder(r - 'A');
}
void Postorder(int root) {
	char l = V[root][0].first, r = V[root][0].second;

	if (isalpha(l)) Postorder(l - 'A');
	if (isalpha(r)) Postorder(r - 'A');
	printf("%c", root + 'A');
}
int main() {
	int n;
	char s[7];

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		cin.getline(s, 7);
		V[s[0] - 'A'].push_back({ s[2], s[4] });
	}
	Preorder(0); printf("\n");
	Inorder(0); printf("\n");
	Postorder(0); printf("\n");
	return 0;
}