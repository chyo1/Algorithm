#include <stdio.h>
#include <deque>
#include <vector>
using namespace std;

vector <int> V;
deque <int> D;

int Get_cnt(int n, int size) {
	int pop, tmp, loc;
	int cnt = 0;

	for (int i = 0; i < size; i++) {
		pop = V[i];

		loc = 0;
		while (D[loc] != pop) loc++; // 뽑으려는 원소의 위치 파악

		// 3. 오른쪽으로 이동
		if (D.size() - loc < loc) {
			for (int j = 0; j < D.size() - loc; j++) {
				tmp = D.back();
				D.pop_back();
				D.push_front(tmp);
				cnt++;
			}
		}

		// 2. 왼쪽으로 이동
		else {
			for (int j = 0; j < loc; j++) {
				tmp = D.front();
				D.pop_front();
				D.push_back(tmp);
				cnt++;
			}		
		}
		// 1번 연산
		D.pop_front();
	}
	return cnt;
}
int main() {
	int N, M, n;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) D.push_back(i + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		V.push_back(n);
	}
	printf("%d", Get_cnt(N, M));

	return 0;
}