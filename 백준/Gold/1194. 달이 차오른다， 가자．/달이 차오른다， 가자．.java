import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class Main {
    static int N, M, groupNum = 1;
    static char[][] map;
    static boolean[][][] visited;
    static List<int[]> paths = new ArrayList<>();

    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        int[] start = new int[2];
        map = new char[N][M];
        visited = new boolean[N][M][1 << 7];
        for (int i = 0; i < N; i++) {
            String input = bf.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = input.charAt(j);

                if (map[i][j] == '0') {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }

        findMinLen(start[0], start[1]);
    }

    private static void findMinLen(int r, int c) {
        Queue<int[]> q = new ArrayDeque<>();
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        q.add(new int[]{r, c, 0, 0});
        visited[r][c][0] = true;
        while (!q.isEmpty()) {
            int[] now = q.poll();
            r = now[0];
            c = now[1];
            int dis = now[2];
            int keys = now[3];

            if (map[r][c] == '1') {
                System.out.println(dis);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nr = now[0] + mv[i][0];
                int nc = now[1] + mv[i][1];

                if (nr < 0 || nc < 0 || N <= nr || M <= nc || visited[nr][nc][keys]) continue;

                if (Character.isLowerCase(map[nr][nc])) {
                    int key = map[nr][nc] - 'a';
                    visited[nr][nc][keys | (1 << key)] = true;
                    q.add(new int[]{nr, nc, dis + 1, keys | (1 << key)});
                } else if (Character.isUpperCase(map[nr][nc])){
                    int door = map[nr][nc] - 'A';
                    if ((keys & (1 << door)) != 0) {
                        visited[nr][nc][keys] = true;
                        q.add(new int[]{nr, nc, dis + 1, keys});
                    };
                } else if (map[nr][nc] != '#'){
                    visited[nr][nc][keys] = true;
                    q.add(new int[]{nr, nc, dis + 1, keys});
                }
            }

        }
        System.out.println(-1);
    }

}