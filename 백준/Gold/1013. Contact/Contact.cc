#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, now, len;
	bool yn;
	string s;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		cin >> s;

		now = 0, yn = true;
		len = s.size();

		while (now < len) {
            if (s[len - 1] == '0') break;
			if (s[now] == '0') { // | 01 )+
				if (s[now + 1] == '0') break; // 01
				else now += 2;
			}

			else { // ( 100+ 1+
				if (now + 1 < len) {
					if (s[now + 1] == '1') break; // 100..이 아닌 경우
				}

				int cnt = 0;
				while (now < len && s[now + 1 + cnt] == '0') cnt++; // 100...0의 개수

				if (cnt < 2) break; // 101...
				else {
					now += cnt + 1;
					cnt = 0;
					while (now < len && s[now + cnt] == '1') cnt++; // 100..1..

					now += cnt;
					if (cnt <= 1) continue; // 100...10..
					if (now + 1 < len&&s[now + 1] == '0') now -= 1; // 100...110..
				}
			}
		}

		// print
		if (now == len) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}