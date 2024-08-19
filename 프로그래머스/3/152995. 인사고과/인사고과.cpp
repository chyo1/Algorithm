#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 근무 태도 내림차순, 동료 평가 오름차순
bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return  a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    vector<int> wan = scores[0];
    int rank = 1, maxB = 0, wanScore = scores[0][0] + scores[0][1];
    
    // 정렬
    sort(scores.begin(), scores.end(), cmp);
    
    // 완호의 순위 구하기
    for (int i = 0; i < scores.size(); i++) {
        if (wan[0] < scores[i][0] && wan[1] < scores[i][1])
            return -1;
        if (maxB <= scores[i][1]) {
            maxB = scores[i][1];
            if (wanScore < scores[i][0] + scores[i][1])
                rank++;
        }
    }
    return rank;
}