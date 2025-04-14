import java.util.*;

class Solution {
    int row, col;
    char IN = '_';
    char OUT = '-';
    char[][] arr;
    int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    boolean[][] visited;
    
    public int solution(String[] storage, String[] requests) {
        row = storage.length;
        col = storage[0].length();
        
        arr = new char[row][col];
        
        for (int i = 0; i < row; i++) {
            arr[i] = storage[i].toCharArray();
        }
        
        int answer = row * col;
        for (String r : requests) {
            answer -= remove(r);
            bfs();
            
//             for (int i = 0; i < arr.length; i++) {
//                 for (int j = 0; j < arr[i].length; j++) {
//                     System.out.print(arr[i][j]);
//                 }
//                 System.out.println();
//             }
//             System.out.println("ans " + answer + "\n");
            
        }
        
        return answer;
    }
    
    private int remove(String r) {
        char del = r.charAt(0);
        int delCnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j] != del) continue;
                
                if (r.length() == 2 || (r.length() == 1 && checkOut(i, j))) {
                    arr[i][j] = IN;
                    delCnt++;
                }
            }
        }
        return delCnt;
    }
    
    private boolean checkOut(int r, int c) {
        if (r == 0 || c == 0 || r == row - 1 || c == col - 1) return true;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (arr[nr][nc] == OUT) return true;
        }
        return false;
    }
    
    private void bfs() {
        visited = new boolean[row][col];
        Queue<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                 if ((i == 0 || j == 0 || i == row - 1 || j == col - 1) && arr[i][j] == IN) {
                    arr[i][j] = OUT;
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j] == OUT && !visited[i][j]) {
                    q.add(new int[]{i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        while (!q.isEmpty()) {
            int[] now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now[0] + dir[i][0];
                int nc = now[1] + dir[i][1];
                if (nr < 0 || nc < 0 || row <= nr || col <= nc || visited[nr][nc]) continue;
                if (arr[nr][nc] == IN) {
                    arr[nr][nc] = OUT;
                    visited[nr][nc] = true;
                    q.add(new int[]{nr, nc});
                }
            }
        }
    }
}