#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

set <string> S;
vector <string> V;

void Get_K(int N, int len) {
	int k = 1;

	while (1) {
		for (int i = 0; i < N; i++) S.insert(V[i].substr(len - k, len));
		if (S.size() == N) {
			printf("%d", k);
			return;
		}
		S.clear();
		k++;
	}
}

int main() {
	int N, n;
	string S;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		V.push_back(S);
	}
	Get_K(N, V[0].length());

	return 0;
}