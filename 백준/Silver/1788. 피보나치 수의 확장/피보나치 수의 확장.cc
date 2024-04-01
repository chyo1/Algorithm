#include <stdio.h>
#include <cmath>
int Fibo[2000002] = { 0,1 };

int main() {
	int n;
	scanf("%d", &n);
	Fibo[1000000] = 0;
	Fibo[999999] = Fibo[1000001] = Fibo[1000002] = 1;
	if (n <= 0) {
		n += 1000000;
		for (int i = 999998; i >= n; i--) {
			Fibo[i] = (Fibo[i + 2] - Fibo[i + 1]) % 1000000000;
		}
	}
	else {
		n += 1000000;
		for (int i = 1000002; i <= n; i++) {
			Fibo[i] = (Fibo[i - 1] + Fibo[i - 2]) % 1000000000;
		}		
	}
	int a = 0;
	if (Fibo[n] > 0) a = 1;
	else if (Fibo[n] < 0) a = -1;
	printf("%d\n%d", a, abs(Fibo[n]));
	return 0;
}