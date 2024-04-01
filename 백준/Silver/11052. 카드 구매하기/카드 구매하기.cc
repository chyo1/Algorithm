#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> P;
int DP[1001][10001]; // DP[카드 개수][가격]

int main() {
	int N, p;

	// input
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p);
		P.push_back(p);
	}

	for (int j = 0; j <= N; j++) DP[0][j] = P[0] * j;

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i + 1 > j) DP[i][j] = DP[i - 1][j];
			else {
				DP[i][j] = DP[i - 1][j] > DP[i][j - i-1] + P[i] ? DP[i - 1][j] : DP[i][j - i-1] + P[i];
			}
		}
	}

	printf("%d", DP[N - 1][N]);

	return 0;
}