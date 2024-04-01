#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque <int> D;
string S;

int Get_res(int N) {
	int i;
	bool front = true;
	for (i = 0; i < N; i++) {
		if (S[i] == 'R')
			front = not front;
		else if (S[i] == 'D') {
			if (!D.size()) {
				printf("error\n");
				return -1;
			}
			if (front) D.pop_front();
			else D.pop_back();
		}
	}
	// 배열이 뒤집혔는 지
	return front;
}
int main() {
	int T, N, n;
	char c;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		cin >> S;
		scanf("%d", &N);
		c = getchar(); // \n
		c = getchar(); //// '['
		for (int i = 0; i < N; i++) {		
			scanf("%d", &n);
			c = getchar(); // ']', ','
			D.push_back(n);
		}
		// 원소 0개일 때 ']' 처리
		if (!N) c = getchar();

		int f = Get_res(S.size());
		// error
		if (f == -1) continue;

		printf("[");
		if (f == 1) {	
			for (int i = 0; i < D.size(); i++) {
				printf("%d", D[i]);
				if (i != D.size() - 1) printf(",");
			}
		}
		else if (f == 0) {
			for (int i = D.size() - 1; i >= 0; i--) {
				printf("%d", D[i]);
				if (i != 0) printf(",");
			}			
		}
		printf("]\n");

		// init
		D.clear();
	}
	return 0;
}