#include <algorithm>
#define INIT -1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // 문자들을 저장할 배열 선언, -1로 초기값 설정
        int alpha[128];
        fill(alpha, alpha + 128, INIT);

        int start = 0, end = 0, ans = 0;
        
        // 문자열 순회
        while (end < s.size()) {
            char c = s[end];
            
            // 현재 substring에 포함된 문자가 나오면
            if (alpha[c] != INIT) {
                
                // 현재까지의 최대 substring 길이
                ans = max(ans, end - start);
                
                // 시작점 갱신
                start = max(alpha[c] + 1, start);
                
                // 문자가 나온 위치 변경
                alpha[c] = end;
            }
            else
                alpha[c] = end;
            end++;
        }
        ans = max(ans, end - start);
        return ans; 
    }
};