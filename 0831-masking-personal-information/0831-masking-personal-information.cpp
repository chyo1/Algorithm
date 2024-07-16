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
        string ans;
        ans += tolower(s[0]);
        ans += "*****";

        int idx = s.find('@');
        s[idx - 1] = tolower(s[idx - 1]);

        for (int i = idx + 1; i < s.size(); i++)
            s[i] = tolower(s[i]);
        ans += s.substr(idx - 1);
        return ans;
    }

    string maskPhone(string &s) {
        int size = s.size(), cnt = 0;
        string localNum = "0000";
        string format[4] = {"***-***-", "+*-***-***-", "+**-***-***-", "+***-***-***-"};
        int idx = 3;
        for (int i = size - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                if (idx >= 0) localNum[idx--] = s[i];
                cnt++;
            }
        }
        string ans = format[cnt - 10] + localNum;
        return ans;
    }
};