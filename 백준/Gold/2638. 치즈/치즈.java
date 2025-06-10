import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static int[][] map;
    private static int n, m;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s[] = bf.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            s = bf.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(s[j]);
            }
        }

        int time = 0;
        while (isMelted()) {
            time++;
        }
        System.out.println(time);
    }

    private static boolean isMelted() {
        int[][] air = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        int[][] mv = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        Queue<Coordinate> q = new LinkedList<>();

        q.add(new Coordinate(0, 0));
        visited[0][0] = true;
        while (!q.isEmpty()) {
            Coordinate now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now.r + mv[i][0];
                int nc = now.c + mv[i][1];
                if (nr < 0 || nc < 0 || n <= nr || m <= nc
                        || visited[nr][nc] || map[nr][nc] == 1) continue;

                visited[nr][nc] = true;
                q.add(new Coordinate(nr, nc));

                for (int j = 0; j < 4; j++) {
                    int nnr = nr + mv[j][0];
                    int nnc = nc + mv[j][1];
                    if (nnr < 0 || nnc < 0 || n <= nnr || m <= nnc
                            || visited[nnr][nnc] || map[nnr][nnc] == 0) continue;
                    air[nnr][nnc]++;
                }
            }
        }

        boolean isChanged = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (air[i][j] >= 2) {
                    map[i][j] = 0;
                    isChanged = true;
                }
            }
        }
        return isChanged;
    }

    private static class Coordinate {
        int r;
        int c;

        public Coordinate(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

}
