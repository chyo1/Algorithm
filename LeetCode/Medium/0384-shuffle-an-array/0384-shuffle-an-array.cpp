class Solution {
private:
    vector<int> ori;

public:
    Solution(vector<int>& nums) {
        ori = nums;
    }
    
    vector<int> reset() {
        return ori;
    }
    
    vector<int> shuffle() {
        vector<int> shuf = ori;
        for(int i = 0; i < shuf.size(); i++) {
            int j = rand() % ori.size();

            swap(shuf[i], shuf[j]);
        }
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */