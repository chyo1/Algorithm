class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size(), cnt = 0;
        bool dp[1001][1001] = {false, };

        for (int i = 0; i < size; i++) {
            dp[i][i] = true;
            cnt++;
        }
        for (int i = 0; i < size - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                cnt++;
            }
        }

        for (int len = 3; len <= size; len++) {
            for (int idx = 0; idx <= size - len; idx++) {
                if (dp[idx + 1][idx + len - 2] && s[idx] == s[idx + len - 1]) {
                    dp[idx][idx + len - 1] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
