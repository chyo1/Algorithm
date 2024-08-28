class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }

    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v;
        int limits[20001] = {0, };

        for (int i = 0; i < values.size(); i++)
            v.push_back({values[i], labels[i]});

        sort(v.begin(), v.end(), cmp);

        int cnt = 0, idx = 0, maxSum = 0;
        while (idx < v.size() && cnt < numWanted) {
            int value = v[idx].first, label = v[idx].second;
            if (limits[label] < useLimit) {
                maxSum += value;
                limits[label]++;
                cnt++;
            }
            idx++;
        }
        return maxSum;
    }
};