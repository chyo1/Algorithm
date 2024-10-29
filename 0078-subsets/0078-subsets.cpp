class Solution {
public:
    vector<vector<int>> ans;
    bool visited[21] = {false, };

    void findAll(vector<int>& nums, int cnt, int size, int startIdx) {
        if (cnt == size) {
            vector<int> v;
            for (int i = 0; i < 21; i++) {
                if (visited[i])
                    v.push_back(i - 10);
            }
            ans.push_back(v);
            return;
        }

        for (int i = startIdx; i < nums.size(); i++) {
            int idxNum = nums[i] + 10;
            if (visited[idxNum]) continue;

            visited[idxNum] = true;
            findAll(nums, cnt + 1, size, i + 1);
            visited[idxNum] = false;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i <= size; i++) {
            findAll(nums, 0, i, 0);
        }
        return ans;
    }
};