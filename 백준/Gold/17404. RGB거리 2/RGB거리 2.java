import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.security.Key;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    private static int N;
    private static final int MAX_VAL = 1000 * 1000;
    private static int[][] dp, colors;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        colors = new int[N][3];

        for (int i = 0; i < N; i++) {
            String[] tmp = bf.readLine().split(" ");
            for (int j = 0; j < 3; j++) {
                colors[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        int ans = MAX_VAL;
        for (int j = 0; j < 3; j++) {
            dp = new int[N][3];
            for (int i = 0; i < 3; i++) {
                if (i == j) dp[0][i] = colors[0][i];
                else dp[0][i] = MAX_VAL;
            }

            for (int i = 1; i < N; i++) {
                dp[i][0] = colors[i][0] + Math.min(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = colors[i][1] + Math.min(dp[i - 1][0], dp[i - 1][2]);
                dp[i][2] = colors[i][2] + Math.min(dp[i - 1][0], dp[i - 1][1]);
            }

            for (int i = 0; i < 3; i++) {
                if (i == j) continue;
                ans = Math.min(ans, dp[N - 1][i]);
            }

        }
        System.out.println(ans);
    }
}
