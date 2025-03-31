import java.util.*;
class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int work : works) {
            pq.add(work);
        }
        
        while (n-- > 0) {
            int now = pq.poll();
            if (now == 0) return 0;
            pq.add(now - 1);
        }
        
        while (!pq.isEmpty()) {
            answer += Math.pow(pq.poll(), 2);
        }
        return answer;
    }
}