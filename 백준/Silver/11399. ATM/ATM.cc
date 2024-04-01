#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, n, sum;
	vector <int> V;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back(n);
	}
	sort(V.begin(), V.end());

	sum = V[0];
	for (int i = 1; i < N; i++) {
		V[i] += V[i - 1];
		sum += V[i];
	}
	printf("%d", sum);
	return 0;
}