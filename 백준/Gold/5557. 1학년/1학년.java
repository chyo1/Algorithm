import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int[] num;
    private static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s = bf.readLine();
        n = Integer.parseInt(s);

        num = new int[n];
        String[] inputs = bf.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(inputs[i]);
        }

        long[][] dp = new long[n - 1][21];
        dp[0][num[0]] = 1;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j <= 20; j++) {
                if (j - num[i] >= 0) dp[i][j] += dp[i - 1][j - num[i]];
                if (j + num[i] <= 20) dp[i][j] += dp[i - 1][j + num[i]];
            }
        }
        System.out.println(dp[n - 2][num[n - 1]]);
    }
}
