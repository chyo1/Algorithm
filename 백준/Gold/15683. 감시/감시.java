import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int N, M, blindSpot;
    private static int[][] room;
    private static int[][][] cctvDir = {
            {},  // 0번은 사용하지 않음
            {{0}, {1}, {2}, {3}},  // 1번 CCTV: 한 방향
            {{0, 2}, {1, 3}},  // 2번 CCTV: 반대 방향
            {{0, 1}, {1, 2}, {2, 3}, {3, 0}},  // 3번 CCTV: 직각 방향
            {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},  // 4번 CCTV: 세 방향
    };
    private static int[][] dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    private static List<Cor> cctv = new ArrayList<>();
    private static List<Cor> cctv5 = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        room = new int[N][M];

        blindSpot = 0;
        for (int i = 0; i < N; i++) {
            inputs = bf.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                room[i][j] = Integer.parseInt(inputs[j]);
                if (room[i][j] == 0) blindSpot++;
                else if (room[i][j] != 6) {
                    if (room[i][j] == 5)
                        cctv5.add(new Cor(i, j));
                    else
                        cctv.add(new Cor(i, j));
                }
            }
        }

        checkCCTV5();
        findMinBlindSpot(0);
        System.out.println(blindSpot);
    }

    private static void checkCCTV5() {
        for (Cor now : cctv5) {
            for (int i = 0; i < 4; i++) {
                int nr = now.r;
                int nc = now.c;
                while (true) {
                    nr += dir[i][0];
                    nc += dir[i][1];
                    if (!(0 <= nr && nr < N && 0 <= nc && nc < M) || room[nr][nc] == 6) break;
                    if (room[nr][nc] == 0) room[nr][nc] = -100;
                }
            }
        }
    }

    private static void findMinBlindSpot(int cctvIdx) {
        if (cctvIdx == cctv.size()) {
            blindSpot = Math.min(blindSpot, countBlindSpot());
            return;
        }

        Cor now = cctv.get(cctvIdx);
        int nowCCTV = room[now.r][now.c];

        changeCCTVDirection(cctvIdx, nowCCTV, now);
    }
    
    private static void changeCCTVDirection(int cctvIdx, int nowCCTV, Cor now) {

        // change cctv direction
        for (int[] directions : cctvDir[nowCCTV]) {
            for (int d : directions) {
                int nr = now.r;
                int nc = now.c;
                while (true) {
                    nr += dir[d][0];
                    nc += dir[d][1];
                    if (!(0 <= nr && nr < N && 0 <= nc && nc < M) || room[nr][nc] == 6) break;
                    if (room[nr][nc] <= 0) room[nr][nc] -= cctvIdx + 1;
                }
            }

            findMinBlindSpot(cctvIdx + 1);

            for (int d : directions) {
                int nr = now.r;
                int nc = now.c;
                while (true) {
                    nr += dir[d][0];
                    nc += dir[d][1];
                    if (!(0 <= nr && nr < N && 0 <= nc && nc < M) || room[nr][nc] == 6) break;
                    if (room[nr][nc] <= 0) room[nr][nc] += cctvIdx + 1;
                }
            }
        }
    }

    private static int countBlindSpot() {
        int blind = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (room[i][j] == 0) blind++;
            }
        }
        return blind;
    }

    static class Cor {
        int r;
        int c;

        public Cor(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
