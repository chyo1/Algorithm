#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> V;
void Num(int last, long long num) {
	V.push_back(num);

	for (int i = 0; i < 10; i++) {
		if (last <= i) break;
		Num(i, num * 10 + i);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 10; i++) Num(i, i);
	sort(V.begin(), V.end());
	if (N > V.size()) printf("-1");
	else printf("%lld", V[N - 1]);
}