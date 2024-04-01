#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	char cmp[5] = "UCPC";
	int now = 0;
	string S;
	getline(cin,S);

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == cmp[now])
			now++;
		if (now == 4) break;
	}
	if (now == 4) printf("I love UCPC\n");
	else printf("I hate UCPC\n");
	return 0;
}