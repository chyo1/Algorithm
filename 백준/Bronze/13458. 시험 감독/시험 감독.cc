#include <stdio.h>
#include <vector>
using namespace std;

vector <int> V;
int main() {
	int N, B, C, n;
	long long int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back(n);
	}
	scanf("%d %d", &B, &C);

	sum += N;
	for (int i = 0; i < N; i++) {
		V[i] -= B;
		if (V[i] > 0) {
			sum += V[i] / C;
			if (V[i] % C) sum++;
		}
	}

	printf("%lld", sum);

	return 0;
}