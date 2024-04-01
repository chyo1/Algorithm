#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int N, val = 0;
    int A[50], B[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	sort(A, A + N);
	sort(B, B + N, greater<>());
	for (int i = 0; i < N; i++) val += A[i] * B[i];
	printf("%d", val);
	return 0;
}