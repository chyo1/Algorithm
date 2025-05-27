import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static int R, C;
    private static int answer = 0;
    private static char[][] map;
    private static boolean[][] visited;
    private static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        R = Integer.parseInt(inputs[0]);
        C = Integer.parseInt(inputs[1]);

        map = new char[R][C];
        visited = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            String input = bf.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = input.charAt(j);
            }
        }

        int alpha = 1 << 27;
        alpha |= 1 << (map[0][0] - 'A');
        visited[0][0] = true;
        findMax(0, 0, alpha, 1);
        System.out.println(answer);
    }

    private static void findMax(int r, int c, int alpha, int moveCount) {
        boolean isMoved = false;
        for (int i = 0; i < 4; i++) {
            int nr = r + mv[i][0];
            int nc = c + mv[i][1];

            if (nr < 0 || nc < 0 || R <= nr || C <= nc
                    || visited[nr][nc] || (alpha & (1 << map[nr][nc] - 'A')) != 0) continue;

            visited[nr][nc] = true;
            findMax(nr, nc, alpha | 1 << (map[nr][nc] - 'A'), moveCount + 1);
            visited[nr][nc] = false;
            isMoved = true;
        }

        if (!isMoved) {
            answer = Math.max(answer, moveCount);
        }
    }
}
