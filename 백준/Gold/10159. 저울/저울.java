import java.io.*;

public class Main {
    private static int N;
    private static int[][] map;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());
        int M = Integer.parseInt(bf.readLine());

        map = new int[N][N];
        for (int i = 0; i < N; i++)
            map[i][i] = 1;

        for (int i = 0; i < M; i++) {
            String[] input = bf.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            map[a - 1][b - 1] = 1;
            map[b - 1][a - 1] = -1;
        }

        // search
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(map[i][k] == 1 && map[k][j] == 1)
                        map[i][j] = 1;

                    if(map[i][k] == -1 && map[k][j] == -1)
                        map[i][j] = -1;
                }
            }
        }

        // output
        for (int i = 0; i < N; i++) {
            int known = 0;
            for (int j = 0; j < N; j++) {
                if (map[i][j] != 0) known++;
            }
            System.out.println(N - known);
        }
    }
}
