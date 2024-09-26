#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    
    int len = sequence.size(), s = 0, e = 0;
    int minLen = 1'000'000, startIdx = 0, sum = sequence[0];
    
    while (s < len && e < len) {
        if (sum == k) {
            if (e - s < minLen) {
                minLen = e - s;
                startIdx = s;
            }
            sum -= sequence[s];
            s++;
        }
        else if (sum < k && e < len - 1) {
            e++;
            sum += sequence[e];
        }
        else {
            sum -= sequence[s];
            s++;
        }
    }
    answer[0] = startIdx, answer[1] = startIdx + minLen;
    return answer;
}