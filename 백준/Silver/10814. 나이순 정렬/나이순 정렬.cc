#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <pair<int, string>> V;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int N, age;
	char name[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &age, &name);
		V.push_back({ age, name });
	}
	stable_sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < V.size(); i++) {
		cout << V[i].first << ' ' << V[i].second << '\n';
	}

	return 0;
}