import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int R, C, T;
    private static final int PURIFIER = -1;
    private static int[][] map, diffusion;
    private static int purifierR;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        R = Integer.parseInt(inputs[0]);
        C = Integer.parseInt(inputs[1]);
        T = Integer.parseInt(inputs[2]);

        map = new int[R][C];
        diffusion = new int[R][C];

        for (int i = 0; i < R; i++) {
            inputs = bf.readLine().split(" ");
            for (int j = 0; j < C; j++) {
                map[i][j] = Integer.parseInt(inputs[j]);
                if (map[i][j] == PURIFIER) {
                    purifierR = i;
                }
            }
        }

        while (T-- > 0) {
            diffuse();
            // for (int i = 0; i < R; i++) {
            //     for (int j = 0; j < C; j++) {
            //         System.out.print(map[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            // System.out.println();
            // System.out.println();

            purify();
            // for (int i = 0; i < R; i++) {
            //     for (int j = 0; j < C; j++) {
            //         System.out.print(map[i][j] + " ");
            //     }
            //     System.out.println();
            // }
        }

        int total = 2;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                total += map[i][j];
            }
        }
        System.out.println(total);
    }

    private static void diffuse() {

        // 확산
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] > 0) {
                    map[i][j] -= getDiffusedAmount(i, j);
                }
            }
        }

        // 확산된 후 양 합산
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (diffusion[i][j] > 0) {
                    map[i][j] += diffusion[i][j];
                    diffusion[i][j] = 0;
                }
            }
        }
    }

    private static int getDiffusedAmount(int r, int c) {
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int diffusedCount = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + mv[i][0];
            int nc = c + mv[i][1];

            if (nr < 0 || nc < 0 || R <= nr || C <= nc || map[nr][nc] < 0) continue;
            diffusion[nr][nc] += map[r][c] / 5;
            diffusedCount++;
        }
        return diffusedCount * (map[r][c] / 5);
    }

    private static void purify() {
        int[][] mvUp = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int[][] mvDown = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        purifyDiffusion(purifierR - 1, 1, mvUp, purifierR - 1);
        purifyDiffusion(purifierR, 1, mvDown, purifierR);

    }

    private static void purifyDiffusion(int r, int c, int[][] mv, int endLoc) {
        int dir = 0;
        int befValue = map[r][c];
        map[r][c] = 0;
        while (r != endLoc || c != 0) {
            int nr = r + mv[dir][0];
            int nc = c + mv[dir][1];

            if (nr < 0 || nc < 0 || R <= nr || C <= nc) {
                dir++;
                continue;
            }

            int tmp = map[nr][nc];
            map[nr][nc] = befValue;
            befValue = tmp;
            r = nr;
            c = nc;
        }
        map[r][c] = -1;
    }
}