#include <stdio.h>
int map[101][101];
int visited[101];
int N;
void DFS(int a);
int cnt = 0;
int main() {
	int M, i, a, b;
	int sum;
	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}
	DFS(1);
	printf("%d", cnt);
	return 0;
}
void DFS(int a) {
	visited[a] = 1;
	
	for (int i = 1; i <= N; i++) {
		if (map[a][i] == 1 && !visited[i]) {
			DFS(i);
			cnt++;
			
		}
	}
}