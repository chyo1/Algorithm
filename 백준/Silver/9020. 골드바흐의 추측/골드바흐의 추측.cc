#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

vector <int> V, P;

void prime();
void Sum(int);

int main() {
	int T, n;
	scanf("%d", &T);
	prime();
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		Sum(n / 2);
	}
	return 0;
}
void prime() {
	int i, j, div;

	for (i = 2; i <= 10000; i++) V.push_back(i);
	for (i = 0; i < V.size(); i++) {
		if (V[i] != 0) {
			div = V[i];
			P.push_back(div);
			for (j = i + div; j < V.size(); j += div) V[j] = 0;
		}
	}
}
void Sum(int n) {
	int s = 0, i = 0, sum;

	while (P[s] < n) s++;
	if (P[s] != n) s--;

	n *= 2;
	while (1) {
		sum = P[s + i] + P[s];

		if (sum == n) break;
		else if (sum > n) s--, i = 1;

		i++;
	}
	printf("%d %d\n", P[s], P[s + i]);
}