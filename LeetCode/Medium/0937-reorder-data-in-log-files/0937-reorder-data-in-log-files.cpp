class Solution {
typedef pair<string, string> ps;
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, ps>> let, dig;

        for (int i = 0; i < logs.size(); i++) {
            int j = 0;
            while (logs[i][j] != ' ')
                j++;
            string sub1 = logs[i].substr(0, j), sub2 = logs[i].substr(j);
            if (isdigit(logs[i][j + 1]))
                dig.push_back({logs[i], {sub1, sub2}});
            else
                let.push_back({logs[i], {sub1, sub2}});
        }

        sort(let.begin(), let.end(), [](pair<string, ps> &a, pair<string, ps> &b) {
            if (a.second.second == b.second.second)
                return a.second.first < b.second.first;
            return a.second.second < b.second.second;
        });
        
        vector<string> ans;
        for (int i = 0; i < let.size(); i++)
            ans.push_back(let[i].first);


        for (int i = 0; i < dig.size(); i++)
            ans.push_back(dig[i].first);

        return ans;
    }
};