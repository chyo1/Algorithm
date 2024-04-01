#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> V;

int Get_High(int N, int M) {
	int min, max, mid, ans;
	long long int total;

	sort(V.begin(), V.end());
	min = 0, max = V[V.size() - 1];

	while (min <= max) {
		total = 0;
		mid = (min + max) / 2;

		for (int i = 0; i < N; i++) {
			if (V[i] > mid) total += V[i] - mid;
		}

		if (total < M)	max = mid - 1;
		else {
			ans = mid;
			min = mid + 1;			
		}
	}
	return ans;
}
int main() {
	int N, M, n;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back(n);
	}

	printf("%d", Get_High(N, M));
	return 0;
}