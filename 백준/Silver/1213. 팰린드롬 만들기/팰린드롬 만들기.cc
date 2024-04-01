#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int alpha[26] = { 0, };
	int N, mid = -1;
	string Name;
	bool odd = false, flag = false;

	cin >> Name;
	N = Name.size();

	// 각 알파벳 개수 세기
	for (int i = 0; i < N; i++) alpha[Name[i] - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 != 0) {

			// 이미 홀수 개의 알파벳이 존재하거나 길이가 짝수일 경우
			if (odd || N % 2 == 0) {
				flag = true; break;
			}

			// 홀수 개의 알파벳의 위치 저장
			else odd = true, mid = i;
		}
	}

	if (flag) printf("I'm Sorry Hansoo");

	// A~Z, Z~A까지 총 알파벳 개수의 반씩 나눠서 출력
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alpha[i] / 2; j++) printf("%c", i + 'A');
		}

		// 길이가 홀수일 경우 중간 글자 출력
		if (mid != -1) printf("%c", mid + 'A');

		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < alpha[i] / 2; j++) printf("%c", i + 'A');
		}
	}

	return 0;
}