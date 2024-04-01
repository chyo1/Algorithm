#include <stdio.h>
#define MAX 1001
int map[MAX][MAX];
int visited[MAX];
int N, M;
void DFS(int a);

int main() {	
	int u, v;
	int i, cnt=0;

	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		map[u][v] = map[v][u] = 1;
	}
	for (i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
void DFS(int a) {
	visited[a] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[a][i] == 1 && !visited[i]) DFS(i);
	}
}