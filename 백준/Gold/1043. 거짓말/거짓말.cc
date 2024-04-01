#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> PARTY[50], member[51];
bool Truth[51];
queue <int> Q;

void know_true() {

	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();

		for (int j = 0; j < member[t].size(); j++) {

			// 진실을 아는 사람이 참가하는 파티
			int party = member[t][j];

			for (int k = 0; k < PARTY[party].size(); k++) {

				// 해당 파티의 참가자 == 진실을 아는/알게 되는 자
				int part = PARTY[party][k];
				if (Truth[part]) continue;
				Truth[part] = true;
				Q.push(part);
			}
		}
	}
}
void LIE(int M) {
	int i, j;
	int cnt = 0;
	for (i = 0; i < M; i++) {
		for (j = 0; j < PARTY[i].size(); j++) {

			// 파티의 참여자 중 진실을 아는 사람이 한 명이라도 있을 경우 중단
			int part = PARTY[i][j];
			if (Truth[part]) break;
		}

		// 진실을 아는 사람이 없을 경우 해당 파티에선 과장 가능
		if (j == PARTY[i].size()) cnt++;
	}
	printf("%d", cnt);
}

int main() {
	int N, M, T, t, num, h;

	// input
	scanf("%d %d", &N, &M);
	scanf("%d", &T); // 진실을 아는 사람 수

	if (!T) {
		printf("%d", M);
		return 0;
	}

	for (int i = 0; i < T; i++) {
		scanf("%d", &t);
		Truth[t] = true;
		Q.push(t);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &h);
			PARTY[i].push_back(h); // 파티의 구성원
			member[h].push_back(i); // 각 사람이 참여하는 파티
		}
	}

	know_true();
	LIE(M);
	return 0;
}