class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0, cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[prev][1] <= intervals[i][0]) {
                prev = i;
                cnt++;
            }
        }
        return intervals.size() - cnt;
    }
};