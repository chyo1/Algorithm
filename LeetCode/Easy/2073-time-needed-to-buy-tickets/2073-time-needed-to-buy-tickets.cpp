class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int val = tickets[k];
        int cnt = 0;
        
        for (int i = 0; i <= k; i++) {
            cnt += min(val, tickets[i]);   
        }
        
        val--;
        for (int i = k + 1, size = tickets.size(); i < size; i++) {
          cnt += min(val, tickets[i]);   
        }
        return cnt;
    }
};