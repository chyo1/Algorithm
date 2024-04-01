#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int N, n, sum = 0;
	queue <int> Q;
	scanf("%d", &N);
	if (N == 1) sum = 0;
	else {
		Q.push(N / 2);
		Q.push(N - Q.front());
		sum = (N / 2) * (N - N / 2);
		while (!Q.empty()) {
			n = Q.front();
			Q.pop();
			if (n == 2) sum += 1;
			else if (n > 1) {
				Q.push(n / 2);
				Q.push(n - n/2);
				sum += (n / 2) * (n - n / 2);
			}
		}
	}
	printf("%d", sum);
	return 0;
}