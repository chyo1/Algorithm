import java.util.*;

class Solution {
    public String solution(String p) {
        return getBalance(p);
    }
    
    private String getBalance(String w) {
        if (w.isEmpty()) return "";
        
        int idx = getBalanceIdx(w);
        String u = w.substring(0, idx);
        String v = w.substring(idx);
        
        if (checkCorrect(u))
            return u + getBalance(v);    
        else {
            StringBuilder sb = new StringBuilder();
            sb.append("(").append(getBalance(v)).append(")");
            for (int i = 1; i < u.length() - 1; i++) {
                if (u.charAt(i) == '(') sb.append(")");
                else sb.append("(");
            }
            return sb.toString();
        }
    }
    
    private int getBalanceIdx(String u) {
        int open = 0, close = 0;
        for (int i = 0; i < u.length(); i++) {
            if (u.charAt(i) == '(') open++;
            else close++;
            if (open == close) return i + 1;
        }
        return u.length();
    }
    
    private boolean checkCorrect(String u) {
        int openCnt = 0;
        for (int i = 0; i < u.length(); i++) {
            if (u.charAt(i) == '(') openCnt++;
            else openCnt--;
            if (openCnt < 0) return false;
        }
        if (openCnt != 0) return false;
        
        return true;
    }
}