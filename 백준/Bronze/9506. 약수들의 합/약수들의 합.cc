#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n, sum = 0;
	vector <int> V;
	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		for (int i = 1; i < n; i++) {
			if (n%i == 0) {
				V.push_back(i);
				sum += i;
			}
		}
		if (sum == n) {
			printf("%d = %d", n, V[0]);
			for (int j = 1; j < V.size(); j++) printf(" + %d", V[j]);
			printf("\n");
		}
		else printf("%d is NOT perfect.\n", n);

		// init
		sum = 0;
		V.clear();
	}
	return 0;
}