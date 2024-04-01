#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

vector <pair<int, int>> V;
bool visited[105];
int fx, fy;

bool Beer(int sx, int sy, int n) {
	queue <pair<int, int>> Q;
	int x, y;

	Q.push({ sx,sy });

	while (!Q.empty()) {
		x = Q.front().first, y = Q.front().second;
		Q.pop();

		if (abs(fx - x) + abs(fy - y) <= 1000) return true;

		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;

			int len = abs(V[i].first - x) + abs(V[i].second - y);
			if (len <= 1000) {
				Q.push({ V[i].first, V[i].second });
				visited[i] = true;
			}
		}
	}
	return false;
}

int main() {
	int t, n, hx, hy, x, y;
	
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {

		// input
		scanf("%d", &n);
		scanf("%d %d", &hx, &hy);

		for (int j = 0; j < n; j++) {
			scanf("%d %d", &x, &y);
			V.push_back({ x,y });
		}

		scanf("%d %d", &fx, &fy);

		// search
		if (Beer(hx, hy, n)) printf("happy\n");
		else printf("sad\n");

		// init
		V.clear();
		fill(visited, visited + n, false);
	}
	return 0;
}