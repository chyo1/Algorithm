#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
	string S;
	vector <int> V;
	int i = 0, total = 0;
	bool minus = false;
	cin >> S;

	while (i < S.size()) {
		int sum = 0;
		while (isdigit(S[i])) {
			sum *= 10;
			sum += S[i] - '0';
			i++;
		}
		if (sum) {
			if (minus) {
				V.push_back(-sum);
				minus = false;
			}
			else V.push_back(sum);
		}
		else {
			if (S[i] == '-') minus = true;
			i++;
		}
	}

	total = V[0];
	for (int i = 1; i < V.size(); i++) {

		if (minus) {
			if (V[i] > 0) total -= V[i];
			else total += V[i];
		}
		else total += V[i];
		if (V[i] < 0) minus = true;
	}
	printf("%d", total);
	return 0;
}