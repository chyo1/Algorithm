class Solution {
public:
    vector<string> ans;
    string nums[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {

        int len = digits.size();
        if (len)
            makeLetterCombinations(digits, "", len);
        return ans;
    }

    void makeLetterCombinations(string &digits, string s, int len) {
        int sLen = s.length();
        if (sLen == len) {
            ans.push_back(s);
            return;
        }

        int idx = digits[sLen] - '0';
        for (int j = 0; j < nums[idx].size(); j++) {
            makeLetterCombinations(digits, s + nums[idx][j], len);
        }
    }
    
};