#include <stdio.h>
#include <vector>
using namespace std;

vector <int> V;

int main() {
	int M, N;
	int i, j, div;
	scanf("%d %d", &M, &N);

	for (i = 2; i <= N; i++) V.push_back(i);
	for (i = 0; i < V.size(); i++) {
		if (V[i] != 0) {
			div = V[i];
			if (div >= M) printf("%d\n", div);

			for (j = i + div; j < V.size(); j += div) V[j] = 0;
		}
	}
	return 0;
}