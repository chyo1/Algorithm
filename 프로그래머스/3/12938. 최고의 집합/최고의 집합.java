import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];
        Arrays.fill(answer, s / n);
        
        int remain = s - s / n * n;
        int idx = n - 1;
        while (remain-- > 0)
            answer[idx--]++;
        
        if (answer[0] == 0)
            return new int[] {-1};
        return answer;
    }
}