class Solution {
public:
    int maxCnt = 0;
    set<string> uniqueSubstring;
    void makeMaximumSubstrings(set<string> uniqueSubstring, string s) {
        if (s == "") {
            maxCnt = max(maxCnt, (int)uniqueSubstring.size());
            return;
        }
        int len = 1;
        while (len < s.size()) {
            string subStr = s.substr(0, len);
            if (uniqueSubstring.insert(subStr).second) {
                makeMaximumSubstrings(uniqueSubstring, s.substr(len));
                uniqueSubstring.erase(subStr);
            }
            len++;
        }
        if (uniqueSubstring.insert(s).second)
            makeMaximumSubstrings(uniqueSubstring, "");
    }
    int maxUniqueSplit(string s) {
        makeMaximumSubstrings(uniqueSubstring, s);
        return maxCnt;
    }
};