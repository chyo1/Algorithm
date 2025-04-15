import java.util.*;
class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        
        long answer = 0;
        long start = 0;
        long end = (long)times[times.length - 1] * n;
        
        while (start <= end) {
            long mid = (start + end) / 2;
            if (countUntillMid(times, mid) < n) {
                start = mid + 1;
            } else {
                answer = mid;
                end = mid - 1;
            }
        }
        return answer;
    }
    
    private long countUntillMid(int[] times, long endTime) {
        long count = 0;
        for (int t : times) {
            if (endTime < t) break;
            count += endTime / t;
        }
        return count;
    }
}