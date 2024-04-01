#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector <pair<int, pair<int, int >>> Com;
int R[1001];
int Find(int n) {
	if (R[n] == n) return n;
	return Find(R[n]);
}
void Union(int a, int b) {
	int aroot, broot;
	aroot = Find(a);
	broot = Find(b);
	R[broot] = aroot;
}

int Kruskal(int N) {
	for (int i = 1; i <= N; i++) R[i] = i;

	int start, end, cost = 0;

	for (int i = 0; i < Com.size(); i++) {
		start = Com[i].second.first, end = Com[i].second.second;

		if (Find(start) != Find(end)) {
			cost += Com[i].first;
			Union(start, end);
		}

	}
	return cost;
}

int main() {
	int N, M, a, b, c;
	scanf("%d\n%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Com.push_back({ c,{a,b} });
		//if (a != b) Com.push_back({ c,{b,a} });
	}
	sort(Com.begin(), Com.end());
	printf("%d", Kruskal(N));
	return 0;
}