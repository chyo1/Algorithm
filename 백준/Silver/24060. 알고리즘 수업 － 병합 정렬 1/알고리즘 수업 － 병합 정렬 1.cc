#include <stdio.h>
#include <vector>
using namespace std;
vector <int> V;

int N, K, cnt = 0;
int *tmp;
void merge(vector <int> &V, int s, int m, int e) {

	int i, j, t;
	i = s, j = m + 1, t = 1;
	while (i <= m && j <= e) {
		if (V[i] <= V[j]) tmp[t++] = V[i++];
		else tmp[t++] = V[j++];
	}
	while (i <= m) tmp[t++] = V[i++];
	while (j <= e) tmp[t++] = V[j++];

	i = s, t = 1;
	while (i <= e) {
		V[i++] = tmp[t++];
		if (++cnt == K) printf("%d", tmp[t - 1]);
	}
}
void merge_sort(vector <int> &V, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;

		merge_sort(V, start, mid); // 앞부분
		merge_sort(V, mid + 1, end); // 뒷부분
		merge(V, start, mid, end); // 병합
	}
}
int main() {
	int n;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back(n);
	}

	tmp = new int[N];
	merge_sort(V, 0, N - 1);

	if (cnt < K) printf("-1");
	//for (int i = 0; i < N; i++) printf("%d ", V[i]);
	//delete[] tmp;
	return 0;
}