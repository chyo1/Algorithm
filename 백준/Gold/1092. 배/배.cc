#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a > b; }
vector <int> L, W, Pop;

void Time() {
	int l, w, t = 0, i;
	
	sort(L.begin(), L.end(), cmp);
	sort(W.begin(), W.end(), cmp);
	if (L.front() < W.front()) {
		printf("-1");
		return;
	}
	// 박스 무게보다 크레인 무게가 작으면 제거
	while (L.back() < W.back()) L.pop_back();

	while (!W.empty()) {
		l = 0;
		for (i = 0; i < W.size(); i++) {
			if (W[i] <= L[l]) {
				l++;
				Pop.push_back(i);
			}
			if (l == L.size()) break;
		}

		for (int i = 0; i < Pop.size(); i++) W.erase(W.begin() + (Pop[i]-i));
		Pop.clear();
		t++;
	}
	printf("%d", t);
}

int main() {
	int N, M, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		L.push_back(n);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		W.push_back(n);
	}
	Time();

	return 0;
}
