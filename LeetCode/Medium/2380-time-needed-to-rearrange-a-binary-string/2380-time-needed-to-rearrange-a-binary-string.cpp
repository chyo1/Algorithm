class Solution {
 public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0;
        while (1) {
            bool flag = false;
            int i = 0;
            while (i < s.size()) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1', s[i + 1] = '0';
                    flag = true;
                    i += 2;
                }
                else
                    i++; 
            }
            if (!flag)
                return cnt;
            cnt++;
        }
        return cnt;
    }
};