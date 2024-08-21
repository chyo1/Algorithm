class Solution {
public:
    vector<int> alpha[26];
    bool visited[26] = {false, };
    int ansLen = 0;
    string ans;
    bool findLexiOrder(string s, int loc) {
        // cout << "s :" << s << "  loc : " << loc << endl;
        if (s.size() == ansLen) {
            ans = s;
            return true;
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i].empty() || visited[i]) continue;
            for (int j = 0; j < alpha[i].size(); j++) {
                if (loc < alpha[i][j]) {
                    visited[i] = true;
                    char c = 'a' + i;
                    // cout << "s :" << s += (i + 'a') << "  loc : " << alpha[i][j] << endl;
                    if (findLexiOrder(s + c, alpha[i][j]))
                        return true;
                    visited[i] = false;
                }
            }
        }
        return false;
    }
    string removeDuplicateLetters(string s) {
        for (int i = 0; i < s.size(); i++) {
            alpha[s[i] - 'a'].push_back(i);
            if (alpha[s[i] - 'a'].size() == 1) ansLen++;
        }
        findLexiOrder("", -1);
        return ans;
    }
};