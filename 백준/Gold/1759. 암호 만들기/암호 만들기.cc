#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector <char> V;
vector <string> S;
bool visited[15];

void Password(int cnt1, int cnt2, string p) { // 모음, 자음의 갯수
	int len = p.length();

	// 문자열의 길이가 2 이상일 때(비교할 수 있는 문자가 존재할 때), 뒤의 문자가 더 작으면 실행 x
	if (len >= 2 && p[len - 2] > p[len - 1]) return;

	// 모음과 자음의 갯수가 조건을 충족하지 못하면 저장 x
	if (len == L) {
		if (cnt1 >= 1 && cnt2 >= 2) S.push_back(p);
		return;
	}

	// 완전탐색
	for (int i = 0; i < C; i++) {
		if (!visited[i]) {
			visited[i] = true;

			// 모음, 자음에 따라 함수 실행
			if (V[i] == 'a' || V[i] == 'e' || V[i] == 'i' || V[i] == 'o' || V[i] == 'u') Password(cnt1 + 1, cnt2, p + V[i]);
			else Password(cnt1, cnt2 + 1, p + V[i]);

			visited[i] = false;
		}
	}
}

int main() {
	char c[2];

	// input
	scanf("%d %d\n", &L, &C);
	for (int i = 0; i < C; i++) {
		
		// 공백 처리를 위해 문자열로 입력 받음
		scanf("%s", &c);
		V.push_back(c[0]);
	}

	// 오름차순 정렬 후 실행
	sort(V.begin(), V.end());
	Password(0, 0, "");

	// print
	for (auto i = S.begin(); i != S.end(); i++) cout << *i << '\n';

	return 0;
}