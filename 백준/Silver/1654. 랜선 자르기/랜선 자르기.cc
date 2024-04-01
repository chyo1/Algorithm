#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector <int> V;
int length(int K, int N) {
	sort(V.begin(), V.end());

	long long int mid, cnt, max = 1, start = 1, end = V[K - 1];

	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < K; i++)	cnt += (V[i] / mid);

		if (cnt >= N) {
			if (mid > max) max = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	return max;
}
int main() {
	int N, K, len;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", &len);
		V.push_back(len);
	}
	printf("%d", length(K, N));

	return 0;
}