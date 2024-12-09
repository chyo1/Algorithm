class Solution {
public:
    int minSwaps(string s) {
        int start = 0, end = s.size() - 1;
        int cnt = 0;

        stack<int> st;
        while (start <= end) {
            if (s[start] == ']') {
                if (st.empty()) {
                    while (s[end] == ']') end--;
                    s[start] = '[';
                    s[end] = ']';
                    cnt++;
                    st.push('[');
                }
                else st.pop();
            }
            else
                st.push('[');
            start++;
        }
        return cnt;
    }
};