#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <string> V;
int main() {
	int N, i, cnt = 1;
	string S;
	bool flag = false;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		V.push_back(S.substr(0, 1));
	}

	sort(V.begin(), V.end());

	i = 0;
	while (i < N - 1) {
		if (V[i] == V[i + 1]) cnt++;
		else {
			if (cnt >= 5) {
				cout << V[i];
				flag = true;
			}
			cnt = 1;
		}
		i++;

	}
	if (cnt >= 5) {
		cout << V[i];
		flag = true;
	}
	if (!flag) printf("PREDAJA");
	return 0;
}