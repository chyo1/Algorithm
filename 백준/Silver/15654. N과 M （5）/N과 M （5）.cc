#include <stdio.h>
#include <algorithm>
using namespace std;
#define size 8

int N[size], print[size];
bool visited[size];

void R(int n, int m, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) printf("%d ", print[i]);
		printf("\n");
		return;
	}

	int now;
	for (int i = 0; i < n; i++) {
		now = N[i];
		if (!visited[i]) {
			visited[i] = true;
			print[cnt] = now;
			R(n, m, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &N[i]);
	sort(N, N + n);
	R(n, m, 0);
	return 0;
}