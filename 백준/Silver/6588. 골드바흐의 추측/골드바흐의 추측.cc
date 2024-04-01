#include <stdio.h>
#include <vector>
using namespace std;

int flag[1000001];
vector <int> Isprime;

void Chae(int N);

int main() {
	int N, P;
	int i, j, cnt;

	Chae(1000000);
	cnt = Isprime.size();

	while (1) {
		scanf("%d", &N);
		if (N == 0) break;

		for (i = 0; i <= cnt / 2; i++) {
			if (!flag[N - Isprime[i]]) {
				printf("%d = %d + %d\n", N, Isprime[i], N - Isprime[i]);
				break;
			}
		}
		if (i == cnt) printf("Goldbach's conjecture is wrong.");
	}
	return 0;
}

void Chae(int N) {
	int i, j, P;
	for (i = 3; i <= N; i += 2) {
		if (!flag[i]) {
			P = i;
			Isprime.push_back(i);
			for (j = 3 * P; j <= N; j += 2 * P) {
				if ((j%P == 0) && (!flag[j])) flag[j]++;
			}
		}
	}
} //소수 판별