#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> V;
vector <char> Op, Seq;
bool visited[100];
int N;
int Min = INT_MAX, Max = INT_MIN;

int Cal() {
	int res = V[0];
	char op;
	for (int i = 1; i < N; i++) {
		op = Seq[i - 1];
		if (op == '+') res += V[i];
		else if (op == '-') res -= V[i];
		else if (op == '*') res *= V[i];
		else if (op == '/') res /= V[i];
	}
	return res;
}
void Get(int s) {
	if (Seq.size() == s) {
		int res = Cal();
		if (Min > res) Min = res;
		if (Max < res) Max = res;
		return;
	}

	for (int i = 0; i < s; i++) {
		char c = Op[i];
		if (!visited[i]) {
			visited[i] = true;
			Seq.push_back(c);
			Get(s);
			visited[i] = false;
			Seq.pop_back();
		}
	}

}
int main() {
	int n, op[4];
	char c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		V.push_back(n);
	}
	for (int i = 0; i < 4; i++) {
		if (i == 0) c = '+';
		else if (i == 1) c = '-';
		else if (i == 2) c = '*';
		else c = '/';

		scanf("%d", &op[i]);
		for (int j = 0; j < op[i]; j++) Op.push_back(c);
	}
	Get(N - 1);
	printf("%d\n%d", Max, Min);
	return 0;
}