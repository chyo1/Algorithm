#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector <string> V;
bool cmp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}
void Print() {
	printf("%s\n", V[0].c_str());
	for (int i = 1; i < V.size(); i++) {
		if (V[i - 1] == V[i]) continue;
		printf("%s\n", V[i].c_str());
		//cout << V[i] << endl;
	}

}
int main() {
	int N;
	char s[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &s);
		V.push_back(s);
	}
	sort(V.begin(), V.end(), cmp);
	Print();
	return 0;
}
//https://bayabashut.tistory.com/38