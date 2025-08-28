import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N, M;
    static char[][] map;
    static boolean[][] visited;

    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        // input
        map = new char[N][M];
        for (int i = 0; i < N; i++) {
            String input = bf.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = input.charAt(j);
            }
        }

        visited = new boolean[N][M];
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt = dfs(i, 1) ? cnt + 1 : cnt;
        }
        System.out.println(cnt);
    }

    static boolean dfs(int r, int c) {
        if (c == M) return true;
        int[] mv = {-1, 0, 1};
        for (int j = 0; j < 3; j++) {
            int nr = r + mv[j];

            if (nr < 0 || N <= nr || map[nr][c] == 'x' || visited[nr][c]) continue;
            visited[nr][c] = true;
            if (dfs(nr, c + 1)) return true;
        }
        return false;
    }

}