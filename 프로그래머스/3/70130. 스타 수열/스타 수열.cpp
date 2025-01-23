#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
    int n = a.size();
    int cnt[500000] = {0, };

    for (int n : a)
        cnt[n]++;

    int maxCnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] <= maxCnt) continue;

        int count = 0;
        for (int j = 0; j < n - 1; j++) {
            if ((a[j] == i || a[j + 1] == i) && a[j] != a[j + 1]) {
                count++;
                j++;
            }
        }
        maxCnt = max(maxCnt, count);
    }
    return maxCnt * 2;
}