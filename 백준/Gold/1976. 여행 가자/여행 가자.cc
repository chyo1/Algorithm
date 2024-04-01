#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	bool city[201][201] = { 0, };
	vector <int> plan;
	int N, M, n;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &city[i][j]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		plan.push_back(n);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			city[i][i] = true;
			for (int j = 1; j <= N; j++) {
				if (city[i][j]) continue;
				if (city[i][k] && city[k][j]) city[i][j] = true;
			}
		}
	}

	for (int i = 0; i < M - 1; i++) {
		int s = plan[i], e = plan[i + 1];
		if (!city[s][e]) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}