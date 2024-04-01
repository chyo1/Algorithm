#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> A;

int main() {
	int N, M, n;
	int up, down;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		A.push_back(n);
	}
	sort(A.begin(), A.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
        printf("%d ", upper_bound(A.begin(), A.end(), n) - lower_bound(A.begin(), A.end(), n));
	}
	return 0;
}