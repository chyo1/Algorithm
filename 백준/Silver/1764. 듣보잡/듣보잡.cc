#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set <string> A, B;
int main() {
	int N, M;
	string S;
    
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		cin >> S;
		A.insert(S);
	}
	for (int i = 0; i < M; i++) {
		cin >> S;
		if (A.find(S) != A.end()) B.insert(S);
	}
    
	printf("%d\n", B.size());
	for (auto iter = B.begin();iter!=B.end();++iter) {
		cout << *iter << '\n';
	}
	return 0;
}