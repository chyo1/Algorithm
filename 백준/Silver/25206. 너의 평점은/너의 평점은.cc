#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

double Get_lev(string S) {
	if (S[0] == 'A') {
		if (S[1] == '+') return 4.5;
		else return 4.0;
	}
	else if (S[0] == 'B') {
		if (S[1] == '+') return 3.5;
		else return 3.0;
	}
	else if (S[0] == 'C') {
		if (S[1] == '+') return 2.5;
		else return 2.0;
	}
	else if (S[0] == 'D') {
		if (S[1] == '+') return 1.5;
		else return 1.0;
	}
	else if (S[0] == 'F') return 0;
	else return -1;

}
int main() {
	string name, lev;
	double num, sum = 0, record;
	int div = 0;
	for (int i = 0; i < 20; i++) {

		cin >> name;
		scanf("%lf", &num);
		cin >> lev;

		record = Get_lev(lev);
		if (record == -1) continue;
		sum += num * record;
		div += num;

	}
	printf("%lf", sum / div);
	return 0;
}