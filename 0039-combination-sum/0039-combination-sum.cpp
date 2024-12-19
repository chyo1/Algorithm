class Solution {
public:
    vector<vector<int>> combinations;

    void findCombinations(vector<int>& candidates, int& target, vector<int> nowCombination, int nowSum, int idx) {
        if (nowSum == target) {
            combinations.push_back(nowCombination);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (nowSum + candidates[i] <= target) {
                nowCombination.push_back(candidates[i]);
                findCombinations(candidates, target, nowCombination, nowSum + candidates[i], i);
                nowCombination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nowCombination;
        findCombinations(candidates, target, nowCombination, 0, 0);
        return combinations;
    }
};