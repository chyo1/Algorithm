class Solution {
private:
    #define MAX_VAL 100000
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int cnt[10001];

        // 최대 값으로 초기화
        fill(cnt, cnt + 10001, MAX_VAL);

        cnt[0] = 0;
    
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];

            for (int j = 1; j <= amount; j++) {
                
                // 현재 동전 가격 < 총 양이라면 적은 값으로 갱신
                if (coin <= j)
                    cnt[j] = min(cnt[j], cnt[j - coin] + 1);
            }
        }
        return cnt[amount] != MAX_VAL ? cnt[amount] : -1;
    }

};