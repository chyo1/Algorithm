class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        vector<vector<int>> v;
        vector<int> ans;

        for (int n : nums)
            m[n]++;

        for (auto iter = m.begin(); iter != m.end(); iter++)
            v.push_back({iter->second, iter->first});

        sort(v.rbegin(), v.rend());

        for (int i = 0; i < k; i++)
            ans.push_back(v[i][1]);

        return ans;
    }
};