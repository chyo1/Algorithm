#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector <pair<int, int>> V[10001];
bool visited[10001];
int node, ans;
void DFS(int start, int value) {
	visited[start] = true;
	if (value > ans) ans = value, node = start;
	for (int i = 0; i < V[start].size(); i++) {
		int ns = V[start][i].first;
		int nv = V[start][i].second + value;
		if (!visited[ns]) {
			DFS(ns, nv);
			visited[ns] = false;
		}
	}
}
int main() {
	int n;
	int p, c, v;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &p, &c, &v);
		V[p].push_back({ c,v });
		V[c].push_back({ p,v });
	}
	DFS(1, 0);
	memset(visited, false, n + 1);
	ans = 0;
	DFS(node, 0);
	printf("%d", ans);
	return 0;
}