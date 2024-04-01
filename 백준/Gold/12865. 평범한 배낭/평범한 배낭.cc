#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> G;
int DP[101][100001]; // DP[물건][배낭 무게]

int main() {
	int N, K, W, V;

	// input
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &W, &V);
		G.push_back({ W,V });
	}

	G.push_back({ 0,0 }); // DP[0]을 비워주기 위해
	sort(G.begin(), G.end());

	// 초기 값은 0
	for (int j = 0; j < N; j++) DP[0][j] = 0;

	for (int i = 1; i <= N; i++) {
		int weight = G[i].first, value = G[i].second;
		for (int j = 0; j <= K; j++) {

			// 현재 보석의 무게와 배낭 사이즈 비교
			if (weight > j) DP[i][j] = DP[i - 1][j];

			// MAX( 무게가 j일 때 i-1번 째 보석을 택한 가치, [i-1번째 보석 선택 + 무게 j-i번째 보석의 무게]+i번째 보석 선택한 가치)
			else DP[i][j] = DP[i - 1][j] > DP[i - 1][j - weight] + value ? DP[i - 1][j] : DP[i - 1][j - weight] + value;
		}
	}
	printf("%d", DP[N][K]);
	return 0;
}