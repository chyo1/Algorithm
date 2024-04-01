#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int N, B;
	vector <int> V;

	scanf("%d %d", &N, &B);

	// 숫자를 36진수 형태로 나눠줌
	while (N != 0) {
		V.push_back(N%B);
		N /= B;
	}

	// 10을 넘어간다면 알파벳으로 바꿔서 출력
	for (int i = V.size() - 1; i >= 0; i--) {
		if (V[i] >= 10) printf("%c", V[i] - 10 + 'A');
		else printf("%d", V[i]);
	}

	return 0;
}