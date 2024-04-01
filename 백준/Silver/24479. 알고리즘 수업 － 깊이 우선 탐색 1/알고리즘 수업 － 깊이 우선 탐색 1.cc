#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> V[100001];
int visited[100001];
int N, M, R, cnt = 0;

void DFS(int R) {
	visited[R] = ++cnt;
	for (int i : V[R]) {
		if (!visited[i]) DFS(i);
	}
}

int main() {

	int a, b;
	scanf("%d %d %d", &N, &M, &R);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (V[i].size() > 1)
			sort(V[i].begin(), V[i].end());
	}

	DFS(R);
	for (int i = 1; i <= N; i++) {
		printf("%d\n", visited[i]);
	}
	return 0;
}