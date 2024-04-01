#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <int> V, R;
int Range[8001];
int main() {
	int N, n;
	int mid, most, range, max = 0;
	double sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back(n);
		sum += n;
		int loc = n + 4000;
		Range[loc]++;

		if (Range[loc] > max) {
			R.clear();
			max = Range[loc];
			R.push_back(n);
		}
		else if (Range[loc] == max) R.push_back(n);
	}
	sort(V.begin(), V.end());
	sort(R.begin(), R.end());
	if (R.size() == 1) mid = R[0];
	else if (R.size() > 1) mid = R[1];
	range = V[N - 1] - V[0];
	printf("%d\n%d\n%d\n%d\n", int(round(sum /N)), V[N / 2], mid, range);
	return 0;
}