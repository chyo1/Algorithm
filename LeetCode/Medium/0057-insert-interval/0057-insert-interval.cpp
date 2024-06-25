class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int size = intervals.size();

        int i = 0;
        while (i < size && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);

        int start = newInterval[0], end = newInterval[1];
        while (i < size && intervals[i][0] <= newInterval[1]) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        ans.push_back({start, end});
        
        while (i < size)
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};