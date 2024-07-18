class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0, len = s.size();
        if (!len) return 0;

        stack<int> bef;
        bef.push(-1);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                bef.push(i);

            else if (bef.size()) {
                bef.pop();
                if (bef.empty())
                    bef.push(i);
                else
                    longest = max(longest, i - bef.top());
            }
        }
        return longest;
    }
};