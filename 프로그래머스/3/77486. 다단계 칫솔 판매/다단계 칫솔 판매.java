import java.util.*;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        HashMap <String, Integer> sequences = new HashMap<>();
        int n = enroll.length;
        int[] income = new int[n];
        
        // 판매책의 조직 구성원 이름 - 순서쌍 저장
        for (int i = 0; i < n; i++) 
            sequences.put(enroll[i], i);
        
        for (int i = 0; i < seller.length; i++) {
            int nowIncome = amount[i] * 100;
            String nowSeller = seller[i];
            
            while (!nowSeller.equals("-") && nowIncome > 0) {
                String nowGetter = referral[sequences.get(nowSeller)];
                
                int divide = nowIncome / 10;
                if (!"-".equals(nowGetter))
                    income[sequences.get(nowGetter)] += divide;
                
                if (!nowSeller.equals(seller[i]))
                    income[sequences.get(nowSeller)] -= divide;
                
                // System.out.println(nowSeller + " " + nowGetter + " " + divide + " " + nowIncome);
                nowIncome = divide;
                nowSeller = nowGetter;
            }
            income[sequences.get(seller[i])] += amount[i] * 90;
        }
        
        return income;
    }
}