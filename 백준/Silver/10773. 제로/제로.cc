#include <stdio.h>
#include <stack>
using namespace std;
stack <int> S;

int main() {
	int K, n, sum = 0;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &n);
		if(n) S.push(n);
		else S.pop();
	}
	while (!S.empty()) {
		sum += S.top();
		S.pop();
	}
	printf("%d", sum);
	return 0;
}