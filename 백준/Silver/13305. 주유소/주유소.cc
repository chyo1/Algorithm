#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <unsigned long long int> Road, Oil;
int main() {
	unsigned long long int N, r, o;
	scanf("%llu", &N);

	// input
	for (int i = 0; i < N - 1; i++) {
		scanf("%llu", &r);
		Road.push_back(r);
	}

	for (int i = 0; i < N; i++) {
		scanf("%llu", &o);
		Oil.push_back(o);
	}

	unsigned long long int money = Road[0] * Oil[0];
	o = Oil[0];
	for (int i = 1; i < N - 1; i++) {
		if (o > Oil[i]) {
			o = Oil[i];
		}
		money += o * Road[i];
	}

	printf("%llu", money);
	return 0;
}