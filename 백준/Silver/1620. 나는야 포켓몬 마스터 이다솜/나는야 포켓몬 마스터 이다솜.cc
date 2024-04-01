#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map<string, int> Map1;
string Map2[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		Map1.insert({ s,i });
		Map2[i] = s;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (isdigit(s[0])) cout << Map2[stoi(s)] << "\n";
		else cout << Map1[s] << "\n";

	}
	return 0;
}