#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long > V;
int num[10] = { 9,8,7,6,5,4,3,2,1,0 };

void Desc(long long number, int l, int len, int now) {
	if (l == len) {
		V.push_back(number);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] < now) Desc(number * 10 + num[i], l + 1, len, num[i]);
	}
}
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= 10; i++) Desc(0, 0, i, 10);
	sort(V.begin(), V.end());

	if (N >= V.size()) printf("-1");
	else printf("%lld", V[N]);

	return 0;
}