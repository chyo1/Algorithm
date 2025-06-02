import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int[] nums;
    private static boolean[][] dp;
    private static int N, M;
    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        nums = new int[N];
        dp = new boolean[N][N];
        String[] inputs = bf.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(inputs[i]);
            Arrays.fill(dp[i], false);
            dp[i][i] = true;
        }

        for (int e = 0; e < N; e++) {
            for (int s = 0; s < e; s++) {
                if (e - s > 2) {
                    dp[s][e] = (nums[s] == nums[e]) && dp[s + 1][e - 1];
                } else {
                    dp[s][e] = (nums[s] == nums[e]);
                }
            }
        }

        M = Integer.parseInt(bf.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            inputs = bf.readLine().split(" ");
            int s = Integer.parseInt(inputs[0]) - 1;
            int e = Integer.parseInt(inputs[1]) - 1;

            if (dp[s][e]) {
                sb.append("1\n");
            } else {
                sb.append("0\n");
            }
        }
        System.out.println(sb);
    }
}
