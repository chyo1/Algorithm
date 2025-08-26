import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
    static int N, groupNum = 2;
    static int[][] map;
    static boolean[][] visited;
    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        map = new int[N][N];
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(inputs[j]);

            }
        }

        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    makeGroup(i, j);
                    groupNum++;
                }
            }
        }

        visited = new boolean[N][N];
        int ans = 100_000;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] != 0 && !visited[i][j]) {
                    ans = Math.min(ans, findLen(i, j, map[i][j]));
                    visited = new boolean[N][N];
                }
            }
        }
        System.out.println(ans);
    }

    private static int findLen(int r, int c, int num) {
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r, c, 0});
        visited[r][c] = true;
        
        while (!q.isEmpty()) {
            int[] now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now[0] + mv[i][0];
                int nc = now[1] + mv[i][1];
                if (nr < 0 || nc < 0 || N <= nr || N <= nc || map[nr][nc] == num || visited[nr][nc]) continue;
                if (map[nr][nc] != 0) {
                    return now[2];
                }
                else {
                    q.add(new int[]{nr, nc, now[2] + 1});
                    visited[nr][nc] = true;
                }
            }
        }
        return 100_000;
    }

    private static void makeGroup(int r, int c) {
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r, c});
        map[r][c] = groupNum;
        while (!q.isEmpty()) {
            int[] now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now[0] + mv[i][0];
                int nc = now[1] + mv[i][1];
                if (nr < 0 || nc < 0 || N <= nr || N <= nc || map[nr][nc] != 1 || visited[nr][nc]) continue;
                map[nr][nc] = groupNum;
                q.add(new int[]{nr, nc});
            }
        }
    }
}
