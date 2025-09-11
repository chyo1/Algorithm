import java.util.*;
class Solution {
    public int solution(String name) {
        int answer = 0;
        
        // get move count
        int cnt = name.length() - 1;

        for(int i = 0; i < name.length(); i++){
            // i 이후의 A 구간 찾기
            int index = i + 1;
            while(index < name.length() && name.charAt(index) == 'A') index++;

            // 각 위치에서 가능한 우회 경로 모두 계산
            cnt = Math.min(cnt, i * 2 + name.length() - index);
            cnt = Math.min(cnt, (name.length() - index) * 2 + i);
        }
        
        // get change count
        for (int idx = 0; idx < name.length(); idx++) {
            int alpha = name.charAt(idx) - 'A';
            if (alpha < 26 - alpha) {
                answer += alpha;
            }
            else {
                answer += (26 - alpha);
            }
        }
        return cnt + answer;
    }
}