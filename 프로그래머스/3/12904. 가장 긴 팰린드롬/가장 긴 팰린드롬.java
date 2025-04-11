import java.util.*;

class Solution {
    private String str;
    
    public int solution(String s) {
        str = s;
        
        int answer = 1;
        for (int i = 0; i < s.length(); i++) {
            answer = Math.max(answer, Math.max(oddPal(i), evenPal(i)));
        }
        return answer;
    }
    
    private int oddPal(int mid) {
        int start = mid - 1;
        int end = mid + 1;
        
        while (0 <= start && end < str.length()) {
            if (str.charAt(start) != str.charAt(end)) {
                break;
            }
            start--;
            end++;
        }
        return (end - start - 1);
    }
    
    private int evenPal(int mid) {
        int start = mid;
        int end = mid + 1;
        
        while (0 <= start && end < str.length()) {
            if (str.charAt(start) != str.charAt(end)) {
                break;
            }
            start--;
            end++;
        }
        return (end - start - 1);
    }
}