import java.util.*;

class Solution {
    private int[] answer = new int[2];
    private int[] percent = {0, 10, 20, 30, 40};
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] sales = new int[emoticons.length];
        getAllPrices(users, emoticons, 0, sales);
        return answer;
    }
    
    private void getAllPrices(int[][] users, int[] emoticons, int idx, int[] sales) {
        if (idx == emoticons.length) {
            calculateAndGetMaximumGoal(users, emoticons, sales);
            return;
        }
        
        // 탐색하며 모든 경우의 수 확인
        for (int i = 0; i < percent.length; i++) {
            sales[idx] = percent[i];
            getAllPrices(users, emoticons, idx + 1, sales);
        }
    }
    
    private void calculateAndGetMaximumGoal(int[][] users, int[] emoticons, int[] sales) {
        int plusUsers = 0;
        int total = 0;
        
        for (int i = 0; i < users.length; i++) {
            int amount = 0;
            
            // 이모티콘 탐색
            for (int j = 0; j < emoticons.length; j++) {    
                // 사용자가 원하는 비율 <= 현재 적용된 할인 비율
                if (users[i][0] <= sales[j])
                    amount += emoticons[j] * (100 - sales[j]) / 100;
                
                // 사용자의 이모티콘 플러스 가입 기준 가격 <= 현재 구매 가격
                if (users[i][1] <= amount) {
                    plusUsers++;
                    break;
                }
            }
            
            // 이모티콘 플러스 미가입자의 결제 비용
            if (amount < users[i][1])
                total += amount;
        }
        
        // 최대 결과 확인 및 갱신
        if (answer[0] < plusUsers) {
            answer[0] = plusUsers;
            answer[1] = total;
        }
        else if (answer[0] == plusUsers) {
            answer[1] = Math.max(answer[1], total);
        }
    }
}