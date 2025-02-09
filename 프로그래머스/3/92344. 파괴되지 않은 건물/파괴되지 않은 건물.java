class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        int r = board.length, c = board[0].length;
        int[][] allDamages = new int[r + 1][c + 1];
        
        for (int[] s : skill) {
            int damage = s[0] == 1 ? -s[5] : s[5];
            
            allDamages[s[1]][s[2]] += damage;
            allDamages[s[1]][s[4] + 1] -= damage;
            
            allDamages[s[3] + 1][s[2]] -= damage;
            allDamages[s[3] + 1][s[4] + 1] += damage;
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                allDamages[i][j + 1] += allDamages[i][j];
            }
        }
        
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                allDamages[i + 1][j] += allDamages[i][j];
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] + allDamages[i][j] > 0) answer++;
            }
        }
        return answer;
    }
}