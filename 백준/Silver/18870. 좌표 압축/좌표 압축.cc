#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> V;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
bool ret(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int N, n, val;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back({ i,n });
	}
	sort(V.begin(), V.end(), cmp);

	val = V[0].second;
	V[0].second = 0;

	for (int i = 1; i < V.size(); i++) {
		if (V[i].second > val) {
			val = V[i].second;
			V[i].second = V[i - 1].second + 1;
		}
		else {
			val = V[i].second;
			V[i].second = V[i - 1].second;
		}
	}
	sort(V.begin(), V.end(), ret);

	for (int i = 0; i < V.size(); i++)	printf("%d ", V[i].second);

	return 0;
}