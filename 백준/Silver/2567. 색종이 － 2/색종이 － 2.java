import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static boolean[][] paper;

    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());

        paper = new boolean[200][200];
        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            int r = Integer.parseInt(inputs[0]);
            int c = Integer.parseInt(inputs[1]);

            for (int j = c; j < c + 10; j++) {
                for (int k = r; k < r + 10; k++) {
                    paper[j][k] = true;
                }
            }
        }

        int cnt = 0;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (paper[i][j]) {
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100 || !paper[nx][ny]) {
                            cnt++;
                        }
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
