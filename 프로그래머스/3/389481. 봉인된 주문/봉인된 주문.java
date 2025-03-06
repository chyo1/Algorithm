import java.util.*;

class Solution {
    public String solution(long n, String[] bans) {
        // ban 문자열들의 순서 구함
        List<Long> banSeq = new ArrayList<>();
        for (String ban : bans) {
            banSeq.add(getSeq(ban));
        }
        
        // 정렬 후 n보다 작은 수가 있다면 그만큼 n을 늘려줌
        Collections.sort(banSeq);
        int idx = 0;
        for (int i = 0; i < banSeq.size(); i++) {
            if (banSeq.get(i) <= n) n++;
            else break;
        }
        
        // 답이 될 문자열의 길이 구함
        int len = 0;
        while (Math.pow(26, len) <= n) len++;
        return getStr(n, len);
    }
    
    // 해당 문자열의 순서 구하기
    private long getSeq(String ban) {
        long seq = 0;
        
        int len = ban.length();
        for (int i = 0; i < ban.length(); i++) {
            seq = seq * 26 + (ban.charAt(i) - 'a' + 1);
        }
        return seq;
    }
    
    // 순서(n)에 맞는 문자열 구하기
    private String getStr(long seq, int strLen) {
        StringBuilder sb = new StringBuilder();

        while (seq > 0) {
            seq--;  // 1-based index 보정
            sb.append((char) ('a' + (seq % 26)));
            seq /= 26;
        }
        return sb.reverse().toString();
    }
}