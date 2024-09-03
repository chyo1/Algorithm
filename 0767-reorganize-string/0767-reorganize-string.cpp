class Solution {
public:
    string reorganizeString(string s) {
        int alpha[26] = {0, };
        vector<pair<int,char>> v;

        for (int i = 0; i < s.size(); i++)
            alpha[s[i] - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (alpha[i])
                v.push_back({alpha[i], i + 'a'});
        }

        sort(v.rbegin(), v.rend());

        string ans = "";
        int len = 1;
        for (int i = 0; i < v.size(); i++) {
            // cout << "for: " << v[i].second << endl;
            if (i == 0) {
                ans.append(v[i].first, v[i].second);
            }
            // if (v[i].first == 1) {
            //     ans.append(1, v[i].second);
            // }
            else {
                for (int j = 0; j < v[i].first; j++) {
                    ans.insert(len, string(1, v[i].second));
                    len = len + 2;
                    if (ans.size() < len)
                        len = 1;
                }
            }
            // cout << ans << endl;
        }
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i + 1])
                return "";
        }
        return ans;
    }
};