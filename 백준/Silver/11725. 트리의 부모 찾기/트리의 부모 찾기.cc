#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector <int> V[100001];
int parent[100001];
void BFS(int x) {
	queue <int> Q;
	Q.push(x);
	parent[x] = 1;
	while (!Q.empty()) {
		int n = Q.front();
		Q.pop();
		for (int i : V[n]) {
			if (!parent[i]) {
				parent[i] = n;
				Q.push(i);
			}
		}
	}
	
}
int main() {
	int N;
	int i, a, b;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	BFS(1);
	for (i = 2; i <= N; i++) printf("%d\n", parent[i]);
	return 0;
}