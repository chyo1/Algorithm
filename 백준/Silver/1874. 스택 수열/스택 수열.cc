#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector <int> V;
vector <char> Op;
stack <int> S;

void Is_possible(int);
int main() {
	int n, num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		V.push_back(num);
	}
	Is_possible(n);
	return 0;
}
void Is_possible(int N) {
	int i, n = 1, number;

	for (i = 0; i < N; i++) {
		number = V[i];
		
		if (S.empty()) {
			S.push(n++);
			Op.push_back('+');
		}
		while (S.top() < number) {
			S.push(n++);
			Op.push_back('+');
		}

		if (S.top() == number) {
			S.pop();
			Op.push_back('-');
		}
		else if (S.top() > number) {
			printf("NO\n");
			return;
		}
	}
	for (i = 0; i < Op.size(); i++) printf("%c\n", Op[i]);
}