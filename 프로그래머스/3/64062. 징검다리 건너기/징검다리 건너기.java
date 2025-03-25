import java.util.*;

class Solution {
    public int solution(int[] stones, int k) {
        int size = stones.length;
        
        int start = 200_000_001;
        int end = 0;
        
        // stones 내의 최대, 최솟값 구함
        for (int i = 0; i < size; i++) {
            start = Math.min(start, stones[i]);
            end = Math.max(end, stones[i]);
        }
        
        // 건널 수 있는 사람의 수를 기준으로 이분탐색
        while (start < end) {
            int mid = (start + end + 1) / 2;
            
            // 건널 수 있다면 최솟값 조정
            if (check(k, mid, size, stones))
                start = mid;

            // 건널 수 없다면 최댓값 조정
            else 
                end = mid - 1;
        }
        return start;
    }
    
    private boolean check(int k, int mid, int size, int[] stones) {
        int cnt = 0;
        
        for (int stone : stones) {
            if (stone < mid)
                cnt++;
            else
                cnt = 0;
            
            if (cnt == k) return false;
        }
        return true;
    }
}