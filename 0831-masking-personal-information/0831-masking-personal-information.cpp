class Solution {
public:
    string maskPII(string s) {
        if (isEmail(s))
            return maskEmail(s);
        else
            return maskPhone(s);
    }

    bool isEmail(string& s) {
        return s.find('@') != -1;
    }

    string maskEmail(string &s) {
        string ans = "0*****0";
        ans[0] = tolower(s[0]);

        int idx = s.find('@');
        ans[6] = tolower(s[idx - 1]);

        for (int i = idx + 1; i < s.size(); i++)
            s[i] = tolower(s[i]);
        ans += s.substr(idx);
        return ans;
    }

    string maskPhone(string &s) {
        int size = s.size(), cnt = 0, idx = 3;
        string localNum = "0000", format[4] = {"***-***-", "+*-***-***-", "+**-***-***-", "+***-***-***-"};

        for (int i = size - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                if (idx >= 0) localNum[idx--] = s[i];
                cnt++;
            }
        }
        return format[cnt - 10] + localNum;
    }
};