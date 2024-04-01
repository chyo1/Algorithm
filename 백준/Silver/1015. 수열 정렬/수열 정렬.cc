#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> A, P;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
	int N, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		A.push_back({ i,n });
	}
	//sort(A.begin(), A.end(), cmp);
	stable_sort(A.begin(), A.end(), cmp);
	for (int i = 0; i < N; i++)	P.push_back({ i,A[i].first });

	sort(P.begin(), P.end(), cmp);
	for (int i = 0; i < N; i++) printf("%d ", P[i].first);

	return 0;
}