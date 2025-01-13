import java.util.*;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        HashMap <String, Integer> sequences = new HashMap<>();
        int[] income = new int[enroll.length];
        
        // 판매책의 조직 구성원 이름 - 순서쌍 저장
        for (int i = 0; i < enroll.length; i++) 
            sequences.put(enroll[i], i);
        
        for (int i = 0; i < seller.length; i++) {
            int nowIncome = amount[i] * 100;
            String nowSeller = seller[i];

            income[sequences.get(nowSeller)] += nowIncome;            
            while (!nowSeller.equals("-") && nowIncome > 0) {
                String nowGetter = referral[sequences.get(nowSeller)];
                
                nowIncome /= 10;
                if (!"-".equals(nowGetter))
                    income[sequences.get(nowGetter)] += nowIncome;                
                income[sequences.get(nowSeller)] -= nowIncome;

                nowSeller = nowGetter;
            }
        }
        
        return income;
    }
}