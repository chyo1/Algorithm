#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> V;
queue <pair<int, int>> Q;

int Find_max(int N) {
	int max = 1, max_i = 0;
	for (int i = 0; i < N; i++) {
		if (max < V[i]) max = V[i], max_i = i;
	}
	V[max_i] = 0;
	return max;
}
int main() {
	int T, N, M;
	int n, idx=0, max, cnt = 0;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++) {
			scanf("%d", &n);
			V.push_back(n);
			Q.push({ i,n });
		}
		while (1) {
			max = Find_max(N);
			while (1) {
				idx = Q.front().first, n = Q.front().second;
				if (n == max) break;
				Q.push({ idx,n });
				Q.pop();
				int tmp = V[0]; V[0] = V[N - 1]; V[N - 1] = tmp;
			}
			cnt++;
			if (idx == M) break;
			Q.pop();
		}

		printf("%d\n", cnt);
		V.clear();
		cnt = 0;
		while (!Q.empty()) Q.pop();
	}
	return 0;
}