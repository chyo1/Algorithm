class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans;

        int idx = s.size() - 1;
        int end = 0;
        while (s[end] == ' ')
            end++;

        while (idx >= end) {
            if (s[idx] == ' ') {
                if (st.size()) {
                    while (!st.empty()) {
                        ans.append(1, st.top());
                        st.pop();
                    }
                    ans.append(1, ' ');
                }
            }
            else
                st.push(s[idx]);

            idx--;
        }
        while (!st.empty()) {
            ans.append(1, st.top());
            st.pop();
        }
        return ans;
    }
};