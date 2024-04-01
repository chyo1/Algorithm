#include <stdio.h>
#include <vector>
using namespace std;

vector <int> V, P;

void prime();
int Cnt(int);

int main() {
	int n;
	prime();
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		printf("%d\n", Cnt(n));
	}
	return 0;
}
void prime() {
	int i, j, div;

	for (i = 2; i <= 250000; i++) V.push_back(i);
	for (i = 0; i < V.size(); i++) {
		if (V[i] != 0) {
			div = V[i];
			P.push_back(div);
			for (j = i + div; j < V.size(); j += div) V[j] = 0;
		}
	}
}
int Cnt(int n) {
	int i = 0, cnt;
	while (P[i] <= n) i++;
	cnt = i;
	while (P[i] <= 2 * n) i++;
	cnt = i - cnt;
	return cnt;
}