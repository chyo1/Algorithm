class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], size = prices.size();
        int maxProfit = 0;
    
        for (int i = 1; i < size; i++) {
            if (buy < prices[i])
                maxProfit += prices[i] - buy;
            buy = prices[i];
        }

        return maxProfit;
    }
};