import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.security.Key;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int N, T;
    private static int[] scores;
    private static int[] times;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        T = Integer.parseInt(input[1]);
        scores = new int[N + 1];
        times = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            String[] blockInput = bf.readLine().split(" ");
            Integer time = Integer.parseInt(blockInput[0]);
            Integer score = Integer.parseInt(blockInput[1]);
            times[i] = time;
            scores[i] = score;
        }

        int[][] dp = new int[N + 1][T + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= T; j++) {
                if (j >= times[i])
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - times[i]] + scores[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        System.out.println(dp[N][T]);
    }
}
