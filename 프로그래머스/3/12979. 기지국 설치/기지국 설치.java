import java.util.*;
class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int size = stations.length;

        int idx = 0;
        int now = 1;
        while (now <= n) {
            if (size <= idx || now < stations[idx] - w) {
                answer++;
                now += 2 * w + 1;
            }
            else {
                now = stations[idx] + w + 1;
                idx++;
            }
        }

        return answer;
    }
}