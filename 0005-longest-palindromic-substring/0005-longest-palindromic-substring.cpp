class Solution {
public:
    string longestPalindrome(string s) {
        // dp[len][idx]
        bool dp[1001][1000] = {false, }; 
        
        int size = s.size(), maxLen = 1, maxLoc = 0;

        for (int len = 1; len <= size; len++) {
            for (int idx = 0; idx <= size - len; idx++) {
                if (len == 1) 
                    dp[len][idx] = true;

                else if (len == 2) {
                    if (s[idx] == s[idx + 1]) {
                        dp[len][idx] = true;

                        if (maxLen < len) {
                            maxLen = len;
                            maxLoc = idx;
                        }
                    }
                }

                else {
                    if (dp[len - 2][idx + 1] && s[idx] == s[idx + len - 1]) {
                        dp[len][idx] = true;

                        if (maxLen < len) {
                            maxLen = len;
                            maxLoc = idx;
                        }
                    }
                }
            }
        }
        return s.substr(maxLoc, maxLen);
    }
};