import java.util.*;
class Solution {
    int[][] visited;
    int groupNum = 1, n, m, min, max;
    int[] sum;
    public int solution(int[][] land) {
        n = land.length;
        m = land[0].length;
        sum = new int[m + 1];
        visited = new int[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && visited[i][j] == 0) {
                    min = m;
                    max = 0;
                    visited[i][j] = groupNum;
                    int amount = bfs(land, i, j);
                    
                    groupNum++;
                    sum[min] += amount;
                    sum[max + 1] -= amount;
                }
            }
        }

        int sums = 0;
        int answer = 0;
        for (int i = 0; i < m; i++) {
            sums += sum[i];
            answer = Math.max(sums, answer);
        }
        return answer;
    }
    
    int bfs(int[][] land, int r, int c) {
        Queue<int[]> q = new ArrayDeque<>();
        
        int sum = 0;
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        q.add(new int[]{r, c});
        while (!q.isEmpty()) {
            sum++;
            int[] now = q.poll();
            r = now[0];
            c = now[1];
            min = Math.min(min, c);
            max = Math.max(max, c);
            
            for (int i = 0; i < 4; i++) {
                int nr = r + mv[i][0];
                int nc = c + mv[i][1];
                if (0 <= nr && nr < n && 0 <= nc && nc < m && visited[nr][nc] == 0 && land[nr][nc] == 1) {
                    visited[nr][nc] = groupNum;
                    q.add(new int[]{nr, nc});
                }
            }    
        }
        
        return sum;
    }
}