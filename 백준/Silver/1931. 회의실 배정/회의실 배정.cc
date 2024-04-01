#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> V;
bool cmp(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int N, s, e;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s, &e);
		V.push_back({ s,e });
	}
	sort(V.begin(), V.end(), cmp);

	int cnt = 1, end;
	end = V[0].second;
	for (int i = 1; i < N; i++) {
		if (end <= V[i].first) {
			cnt++;
			end = V[i].second;
		}
	}
	printf("%d", cnt);
	return 0;
}