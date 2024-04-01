#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int s[4];
	for (int i = 0; i < 4; i++) scanf("%d", &s[i]);

	sort(s, s + 4);

	if (s[0] + s[3] - (s[1] + s[2]) > 0) printf("%d", s[0] + s[3] - (s[1] + s[2]));
	else printf("%d", s[1] + s[2] - (s[0] + s[3]));

	return 0;
}