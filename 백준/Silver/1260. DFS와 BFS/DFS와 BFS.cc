#include <stdio.h>
#include <vector>
#include <queue>
std::queue<int> Q;
int visited[1001] = { 0, };
int map[1001][1001];
int N, M, V, i;

void init(int a[], int n);
void DFS(int a, int n);
void BFS(int a, int n);
int main() {
	int N, M, V, i;
	int a, b;
	scanf("%d %d %d", &N, &M, &V);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}
	init(visited, N);
	DFS(V, N);
	init(visited, N);
	printf("\n");
	BFS(V, N);
	return 0;
}
void init(int a[], int n) {
	for (int i = 1; i <= n; i++) a[i] = 0;
}
void DFS(int a, int n) {
	int i;
	visited[a] = 1;
	printf("%d ", a);
	for (i = 1; i <= n; i++) {
		if (map[a][i] == 1 && !visited[i]) DFS(i, n);
	}
}
void BFS(int a, int n) {
	Q.push(a);
	visited[a] = 1;
	while (!Q.empty()) {
		int x = Q.front();
		printf("%d ", x);
		Q.pop();
		for (i = 1; i <= n; i++) {
			if (map[x][i] == 1 && !visited[i]) {
				Q.push(i);
				visited[i] = 1;
			}
		}
	}

}
