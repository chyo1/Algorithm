class Solution {
public:
    int maxCnt = 0;
    unordered_set<string> uniqueSubstring;

    void makeMaximumSubstrings(int startIdx, unordered_set<string>& uniqueSubstring, string& s) {
        if (startIdx == s.size()) {
            maxCnt = max(maxCnt, (int)uniqueSubstring.size());
            return;
        }

        int len = 1;
        while (startIdx + len <= s.size()) {
            string subStr = s.substr(startIdx, len);
            if (uniqueSubstring.insert(subStr).second) {
                makeMaximumSubstrings(startIdx + len, uniqueSubstring, s);
                uniqueSubstring.erase(subStr);
            }
            len++;
        }
    }
    int maxUniqueSplit(string s) {
        makeMaximumSubstrings(0, uniqueSubstring, s);
        return maxCnt;
    }
};