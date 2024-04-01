#include <stdio.h>
using namespace std;

unsigned long long DP[70] = { 1,1,2,4 };

int main(){
	int t, n;

	for (int i = 4; i < 70; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4];
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%llu\n", DP[n]);
	}

	return 0;
}