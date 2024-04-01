#include <stdio.h>
bool Is_six(int n) {
	int cnt = 0;
	
	while (n != 0) {
		if (n % 10 == 6) {
			while (n % 10 == 6) {
				n /= 10;
				cnt++;
				if (cnt == 3) return true;
			}
			
			cnt = 0;
		}
		n /= 10;
	}
	return false;
}
int main() {
	int N, cnt = 1, n = 666;
	scanf("%d", &N);
	while (cnt < N) {
		n++;		
		if (Is_six(n)) cnt++;
	}
	printf("%d", n);
	return 0;
}