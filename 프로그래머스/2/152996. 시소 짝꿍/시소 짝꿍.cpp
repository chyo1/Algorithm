#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long cnt[1001] = {0, };
    
    for (auto w : weights)
        cnt[w]++;
    
    for (int i = 100; i <= 1000; i++) {
        if (cnt[i] == 0) continue;
        
        // 1 : 1
        if (cnt[i] > 1) 
            answer += (cnt[i] * (cnt[i] - 1)) / 2;

        // 1 : 2
        if (i * 2 <= 1000 && cnt[i * 2] > 0)
            answer += cnt[i] * cnt[i * 2];
        
        // 2 : 3
        if (i % 2 == 0 && (i / 2 * 3) <= 1000 && cnt[i / 2 * 3] > 0)
            answer += cnt[i] * cnt[i / 2 * 3];
        
        // 3 : 4
        if (i % 3 == 0 && (i / 3 * 4) <= 1000 && cnt[i / 3 * 4] > 0) 
            answer += cnt[i] * cnt[i / 3 * 4];
    }
    
    return answer;
}

/*
    2 = 2 / 3 = 3 / 4 = 4
    4 = 2
    3 = 2
    4 = 3
*/
