class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans;

        int size = s.size();
        int idx = size - 1;
        int end = 0;
        while (s[end] == ' ')
            end++;

        while (idx >= end) {
            if (s[idx] == ' ') {
                bool flag = false;
                if (st.size())
                    flag = true;

                while (!st.empty()) {
                    ans.append(1, st.top());
                    st.pop();
                }
                if (flag)
                    ans.append(1, ' ');
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