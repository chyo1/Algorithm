#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

vector <int> Sum;

int main() {
	int N, K, n, sum, max = INT_MIN;
	scanf("%d %d", &N, &K);

	Sum.push_back(0);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &n);
		Sum.push_back(Sum[i - 1] + n);
	}

	for (int i = N; i >= K; i--) {
		sum = Sum[i] - Sum[i - K];
		max = max > sum ? max : sum;
	}
	printf("%d", max);

	return 0;
}