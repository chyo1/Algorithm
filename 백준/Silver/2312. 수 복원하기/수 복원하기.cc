#include <stdio.h>
#include <vector>
using namespace std;

vector <int> Prime;

void Get_Prime() {
	bool A[100001] = { 0, };
	int i, j, mul;
	for (i = 2; i <= 100000; i++) {
		if (A[i]) continue;
		for (j = 2; j < i; j++) {
			if (i%j == 0) break;
		}
		if (i == j) {
			A[i] = true;
			Prime.push_back(i);
			mul = i;
			while (mul + i <= 100000) {
				mul += i;
				A[mul] = true;
			}
		}
	}
}
void Print(int n) {
	int i = 0, cnt = 0;
	while (n > 1) {
		while (n%Prime[i] == 0) n /= Prime[i], cnt++;
		if (cnt) printf("%d %d\n", Prime[i], cnt);
		i++, cnt = 0;
	}

}
int main() {
	int T, n;
	scanf("%d", &T);
	Get_Prime();
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		Print(n);
	}

	return 0;
}