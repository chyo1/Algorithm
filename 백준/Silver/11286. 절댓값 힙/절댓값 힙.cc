#include <stdio.h>
#include <queue>

using namespace std;
priority_queue <int, vector<int>, greater <int>> P, M;

int Pop();
int main() {
	int N, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);

		if (!n) printf("%d\n", Pop());
		else if (n > 0) P.push(n);
		else M.push(-n);
	}
	return 0;
}

int Pop() {
	int ret = 0;
	if (P.empty()) {
		if (M.empty()) ret = 0; // both empty
		else {
			ret = -M.top();
			M.pop();
		}
	}
	else {
		if (M.empty()) {
			ret = P.top();
			P.pop();
		}
		else {
			int min_m = M.top(), min_p = P.top();
			if (min_m <= min_p) ret = -min_m, M.pop();
			else ret = min_p, P.pop();
		}
	}

	return ret;
}