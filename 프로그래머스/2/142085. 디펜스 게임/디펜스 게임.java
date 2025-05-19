import java.util.*;
class Solution {
    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int answer = enemy.length;
        
        for (int i = 0; i < enemy.length; i++) {
            n -= enemy[i];
            pq.add(enemy[i]);
            if (n < 0) {
                if (0 < k && i - 1 < enemy.length && !pq.isEmpty()) {
                    n += pq.poll();
                    k--;
                }
                else {
                    answer = i;
                    break;
                }
            }
        }
        return answer;
    }
}