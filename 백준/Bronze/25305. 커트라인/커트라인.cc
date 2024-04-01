#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
	int N, k;
	int P[1001];
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) scanf("%d", &P[i]);
	sort(P, P + N, cmp);
	printf("%d", P[k - 1]);
	return 0;
}