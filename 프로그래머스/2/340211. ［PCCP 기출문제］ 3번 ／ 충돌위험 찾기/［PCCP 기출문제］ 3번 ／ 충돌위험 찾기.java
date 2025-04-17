import java.util.*;
class Solution {
    public int solution(int[][] points, int[][] routes) {
        int crashCount = 0;
        int m = routes.length;
        int endIdx = routes[0].length;
        
        // 가야할 곳 정하기
        int[] routeIdxs = new int[m];
        Arrays.fill(routeIdxs, 1);
        
        // 시작 위치 지정
        int[][] cnt = new int[101][101];
        int[][] nowLoc = new int[m][2];
        for (int i = 0; i < m; i++) {
            nowLoc[i][0] = points[routes[i][0] - 1][0];
            nowLoc[i][1] = points[routes[i][0] - 1][1];
            
            cnt[nowLoc[i][0]][nowLoc[i][1]]++;
            if (cnt[nowLoc[i][0]][nowLoc[i][1]] == 2) crashCount++;
        }
        
        // 이동
        boolean isMoved = true;
        while (isMoved) {
            isMoved = false;
            cnt = new int[101][101];
            
            for (int i = 0; i < m; i++) {
                int nextIdx = routeIdxs[i];
                if (nextIdx == endIdx) continue;
                
                isMoved = true;
                
                // 다음 노드로 이동
                int x = nowLoc[i][0], y = nowLoc[i][1];
                int nx = points[routes[i][nextIdx] - 1][0], ny = points[routes[i][nextIdx] - 1][1];
                
                if (x != nx) {
                    x = move(x, nx);
                }
                else if (y != ny){
                    y = move(y, ny);
                }
                
                // 이동 완료 시 목적지 변경
                if (x == nx && y == ny) {
                    routeIdxs[i]++;
                }

                nowLoc[i][0] = x;
                nowLoc[i][1] = y;
                
                cnt[x][y]++;
                if (cnt[x][y] == 2) crashCount++;
            }
        }
        return crashCount;
    }
    
    private int move(int now, int next) {
        if (now < next)
            return now + 1;

        return now - 1;
    }
}