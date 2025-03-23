import java.util.*;
class Solution {
    public int solution(int[] players, int m, int k) {
        int upCount = 0;
        int size = players.length;
        int[] count = new int[size + 1];
        
        int now = 0;
        for (int i = 0; i < size; i++) {
            now += count[i];
            if ((now + 1) * m <= players[i]) {
                int plus = players[i] / m - now;
                
                now += plus;
                count[i] += plus;
                count[Math.min(i + k, size)] -= plus;
                upCount += plus;
            }
        }
            
        return upCount;
    }
}