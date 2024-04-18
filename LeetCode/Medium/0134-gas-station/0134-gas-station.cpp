class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = gas.size();
        int total = 0, curSum = 0, ansIdx = 0;

        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            
            // 다음 주유소까지 갈 수 없음 -> 다음 인덱스부터 탐색
            if (curSum < 0) {
                ansIdx = i + 1;
                curSum = 0;
            }
        }
        
        // 총 합 < 0 -> 한 바퀴 돌 수 없음
        return total < 0 ? -1 : ansIdx;
    }
};