#include <algorithm>
#define INIT -1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[128];
        fill(alpha, alpha + 128, INIT);

        int start = 0, end = 0, ans = 0;
        
        while (end < s.size()) {
            char c = s[end];
            if (alpha[c] != INIT) {
                ans = max(ans, end - start);
                start = max(alpha[c] + 1, start);
                alpha[c] = end;
                // printf("start : %d end : %d ans : %d\n", start, end, ans);
            }
            else {
                alpha[c] = end;
            }
            end++;
        }
                // printf("start : %d end : %d\n", start, end);

        ans = max(ans, end - start);
        return ans; 
    }
};