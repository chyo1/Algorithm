#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(char a, char b) { return a > b; }
int main() {
	char C[11];
	int cnt = 0, i = 0;
	scanf("%s", &C);
	while (C[i++] != NULL) cnt++;
	sort(C, C + cnt, cmp);
	for (i = 0; i < cnt; i++) printf("%c", C[i]);
	return 0;
}