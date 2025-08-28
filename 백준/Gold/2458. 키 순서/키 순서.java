import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N, M;
    static boolean[][] map;

    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        // input
        map = new boolean[N + 1][N + 1];
        for (int i = 0; i < M; i++) {
            inputs = bf.readLine().split(" ");
            int small = Integer.parseInt(inputs[0]);
            int tall = Integer.parseInt(inputs[1]);
            map[small][tall] = true;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (map[i][k] && map[k][j]) map[i][j] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            boolean flag = true;
            for (int j = 1; j <= N; j++) {
                if (i != j && !map[i][j] && !map[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        System.out.println(cnt);
    }
}