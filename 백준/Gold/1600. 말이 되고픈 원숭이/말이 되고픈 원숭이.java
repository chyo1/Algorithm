import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
    static int[][] map;
    static int[][] horse = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static int K, H, W;
    static boolean[][][] visited;
    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        K = Integer.parseInt(bf.readLine());

        String[] inputs = bf.readLine().split(" ");
        W = Integer.parseInt(inputs[0]);
        H = Integer.parseInt(inputs[1]);

        if (W == 1 && H == 1) {
            System.out.println(0);
            return;
        }
        map = new int[H][W];
        visited = new boolean[H][W][K + 1];
        for (int i = 0; i < H; i++) {
            inputs = bf.readLine().split(" ");
            for (int j = 0; j < W; j++) {
                map[i][j] = Integer.parseInt(inputs[j]);
            }
        }

        Queue<Cor> q = new ArrayDeque<>();
        q.add(new Cor(0, 0, 0, 0));
        visited[0][0][0] = true;
        while (!q.isEmpty()) {
            Cor now = q.poll();
//            System.out.println(now.toString());
            if (now.horseCnt < K) {
                for (int i = 0; i < 8; i++) {
                    int nr = now.r + horse[i][0];
                    int nc = now.c + horse[i][1];

                    if (nr < 0 || nc < 0 || H <= nr || W <= nc || map[nr][nc] == 1 || visited[nr][nc][now.horseCnt + 1]) continue;
                    visited[nr][nc][now.horseCnt + 1] = true;
                    if (nr == H - 1 && nc == W - 1) {
                        System.out.println(now.cnt + 1);
                        return;
                    }
                    q.add(new Cor(nr, nc, now.horseCnt + 1, now.cnt + 1));

                }
            }

            for (int i = 0; i < 4; i++) {
                int nr = now.r + mv[i][0];
                int nc = now.c + mv[i][1];

                if (nr < 0 || nc < 0 || H <= nr || W <= nc || map[nr][nc] == 1 || visited[nr][nc][now.horseCnt]) continue;
                visited[nr][nc][now.horseCnt] = true;
                if (nr == H - 1 && nc == W - 1) {
                    System.out.println(now.cnt + 1);
                    return;
                }
                q.add(new Cor(nr, nc, now.horseCnt,now.cnt + 1));
            }
        }
        System.out.println(-1);
    }

    static class Cor {
        int r;
        int c;
        int horseCnt;
        int cnt;

        public Cor(int r, int c, int horseCnt, int cnt) {
            this.r = r;
            this.c = c;
            this.horseCnt = horseCnt;
            this.cnt = cnt;
        }
    }

}
