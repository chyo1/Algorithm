import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    private static int T, K;
    private static int[] files, sums;
    private static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(bf.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        while (T-- > 0) {
            K = Integer.parseInt(bf.readLine());
            files = new int[K + 1];
            sums = new int[K + 1];
            dp = new int[K + 1][K + 1];
            String[] inputs = bf.readLine().split(" ");
            for (int i = 1; i <= K; i++) {
                files[i] = Integer.parseInt(inputs[i - 1]);
                sums[i] += sums[i - 1] + files[i];
            }

            for (int i = 1; i <= K; i++) {
                for (int from = 1; from + i <= K; from++) { // 구간별 최댓값 구하기
                    int to = from + i;
                    dp[from][to] = Integer.MAX_VALUE;

                    for (int mid = from; mid < to; mid++) { // from ~ mid + mid ~ to 최솟값 구하기
                        dp[from][to] = Math.min(dp[from][to],
                                dp[from][mid] + dp[mid + 1][to] + sums[to] - sums[from - 1]);
                    }
                }
            }
            System.out.println(dp[1][K]);
        }
    }
}