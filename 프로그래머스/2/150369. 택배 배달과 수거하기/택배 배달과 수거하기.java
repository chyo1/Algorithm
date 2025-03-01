class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int p = n - 1, d = n - 1;
        
        while (0 <= p || 0 <= d) {
            
            while (0 <= p && pickups[p] == 0)  p--;
            while (0 <= d && deliveries[d] == 0) d--;
            
            answer += Math.max(p, d) + 1;
            
            int pick = 0, del = 0;
            while (0 <= p && pick < cap) {
                if (pick + pickups[p] > cap) {
                    pickups[p] -= cap - pick;
                    pick = cap;
                    break;
                }
                else {
                    pick += pickups[p];
                    pickups[p--] = 0;
                }
            }
            while (0 <= d && del < cap) {
                if (del + deliveries[d] > cap) {
                    deliveries[d] -= cap - del;
                    del = cap;
                    break;
                }
                else {
                    del += deliveries[d];
                    deliveries[d--] = 0;
                }
            }
        }
        return answer * 2;
    }
}