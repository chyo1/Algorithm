#include <stdio.h>
int DP[1000] = { 1, };
int MAX(int a, int b) { return a > b ? a : b; }
int main() {
	int n, max = 1;
	int box[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { 
		scanf("%d", &box[i]); 
		DP[i] = 1;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (box[j] < box[i]) DP[i] = MAX(DP[i], DP[j] + 1);
		}
		max = MAX(max, DP[i]);
	}
	printf("%d", max);
	return 0;
}