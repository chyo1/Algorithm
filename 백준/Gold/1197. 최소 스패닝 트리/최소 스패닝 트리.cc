#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, pair<int, int>>> G;
int root[10001];
int Find(int a) {
	if (root[a] == a) return a;
	return Find(root[a]);
}
void Union(int a, int b) {
	int roota, rootb;
	roota = Find(a);
	rootb = Find(b);
	root[rootb] = roota;
}
void Kru(int size) {
	int start, end, value;
	long long int sum = 0;
	for (int i = 0; i < size; i++) {
		value = G[i].first, start = G[i].second.first, end = G[i].second.second;
		if (Find(start) == Find(end)) continue;
		Union(start, end);
		sum += value;
	}
	printf("%lld", sum);
}
int main() {
	int V, E;

	int a, b, c;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		G.push_back({ c,{a,b} });
	}

	// init
	for (int i = 1; i <= V; i++) root[i] = i;
	sort(G.begin(), G.end());

	Kru(E);

	return 0;
}