#include <stdio.h>
#include <vector>
using namespace std;
vector <int> V[101];
int visited[101];
int DFS(int start, int end) {
	visited[start] = 1;
	if (start == end) return 0;
	int cnt, i, sum = -1;
	for (i = 0; i < V[start].size(); i++) {
		if (!visited[V[start][i]]) {
			cnt = DFS(V[start][i], end);
			if (cnt != -1) sum = cnt + 1;
		}

	}
	return sum;
}
int main() {
	int n, m;
	int s, e, x, y;
	scanf("%d", &n);
	scanf("%d %d", &s, &e);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		V[x].push_back(y);
		V[y].push_back(x);
	}
	printf("%d", DFS(s, e));
	return 0;
}