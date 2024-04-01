#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

vector <int> T1;
int N, Min = INT_MAX;
int S[20][20];
bool visit[20];

void Cal() {
	int s = N / 2;
	vector <int> T2;
	int sum1, sum2, sum;
	sum1 = sum2 = 0;

	// team 2 members
	for (int i = 0; i < N; i++) {
		if (!visit[i]) T2.push_back(i);
	}

	//team 1
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			int t1 = T1[i], t2 = T1[j];
			sum1 += S[t1][t2] + S[t2][t1];
		}
	}

	// team 2
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			int t1 = T2[i], t2 = T2[j];
			sum2 += S[t1][t2] + S[t2][t1];
		}
	}

	sum = sum1 - sum2;
	if (sum < 0) sum = -sum;
	if (sum < Min) Min = sum;
}
void Get_diff(int n) {
	if (T1.size() == n) {
		Cal();
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			if (T1.size() && T1[T1.size() - 1] > i) continue;
			visit[i] = true;
			T1.push_back(i);
			Get_diff(n);
			visit[i] = false;
			//if (T1.size() == 1 && T1[0] == 0) return;
			T1.pop_back();
			if (!T1.size()) return;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	Get_diff(N / 2);
	printf("%d", Min);
	return 0;
}