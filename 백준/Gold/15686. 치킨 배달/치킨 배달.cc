#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector <pair<int, int>> Store;
vector <pair<int, int>> Home;

bool visited[13];
int ans = 100000000;

void Get_dis(int cnt, int M, int now) {

	if (cnt == M) {
		int total = 0;

		for (int i = 0; i < Home.size(); i++) {
			int hx = Home[i].first, hy = Home[i].second;
			int dis = 1000000;

			for (int j = 0; j < Store.size(); j++) {
				if (visited[j] == false) continue;
				int sx = Store[j].first, sy = Store[j].second;
				dis = min(abs(sx - hx) + abs(sy - hy), dis);
			}

			total += dis;
			if (total > ans) return;
		}
		ans = min(ans, total);
		return;
	}

	for (int i = now; i < Store.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		Get_dis(cnt + 1, M, i);
		visited[i] = false;
	}
}
int main() {
	int N, M, loc;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &loc);
			if (loc == 1) Home.push_back({ i,j });
			else if (loc == 2) Store.push_back({ i,j });
		}
	}

	Get_dis(0, M, 0);
	printf("%d", ans);

	return 0;
}