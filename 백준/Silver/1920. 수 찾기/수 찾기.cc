#include <stdio.h>
#include <algorithm>
using namespace std;

int A[100000];
bool Is_in(int n, int N) {
	int start = 0, mid, end = N - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (A[mid] == n) return true;
		else if (A[mid] > n) end = mid - 1;
		else start = mid + 1;
	}
	return false;
}
int main() {
	int N, M, n;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		printf("%d\n", Is_in(n, N));
	}
	return 0;
}