#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	string S;
	priority_queue <int> pq;
	int num, sum = 0;
	bool zero = false;
	cin >> S;
	
	for (int i = 0; i < S.size(); i++) {
		num = S[i] - '0';
		if (!num) zero = true;
		sum += num;

		pq.push(num);
	}
	if (zero&&sum % 3 == 0) {
		while (!pq.empty()) {
			printf("%d", pq.top());
			pq.pop();
		}
	}
	else printf("-1");
	return 0;
}