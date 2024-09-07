class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int idx = 0, size = s.size();
        int l = 0, r = 0;
        while (idx < size) {
            while (idx < size && s[idx] == ' ')
                idx++;
            if (idx == size)
                break;
            while (idx < size && s[idx] != ' ')
                s[r++] = s[idx++];
            reverse(s.begin() + l, s.begin() + r);
            s[r++] = ' ';
            l = r;
        }
        s.resize(r - 1);
        return s;
    }
};