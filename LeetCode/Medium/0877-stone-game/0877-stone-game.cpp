class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size() % 2)
            return false;
        return true;
    }
};