class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> range(2);
        
        int size = intervals.size();

        // sort in start ascending order
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < size; i++) {

            range[0] = intervals[i][0];
            int end = intervals[i][1];

            while (++i < size && intervals[i][0] <= end)
                end = max(end, intervals[i][1]);
            i--;
                
            range[1]= end;
            ans.push_back(range);
        }
        return ans;
    }
};