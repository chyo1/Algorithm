import java.util.*;
class Solution {
    private static int answer = 121;
    private boolean[][][] vis;
    public int solution(int[][] info, int n, int m) {
        int len = info.length;
        vis = new boolean[len][n + 1][m + 1];
        dfs(info, 0, 0, 0, n, m);
        return answer == 121 ? -1 : answer;
    }
    
    private void dfs(int[][] info, int idx, int a, int b, int n, int m) {
        if (n <= a || m <= b) return;
        if (idx == info.length) {
            answer = Math.min(a, answer);
            return;
        }
        
        if (vis[idx][a][b]) return;
        vis[idx][a][b] = true;
        
        dfs(info, idx + 1, a, b + info[idx][1], n, m);
        dfs(info, idx + 1, a + info[idx][0], b, n, m);
        return;
    }
}