import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static final int INF = 16_000_000;
    private static int N;
    private static int end;
    private static int[][] money;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        money = new int[N][N];
        dp = new int[N][1 << N];
        end = (1 << N) - 1;

        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                money[i][j] = Integer.parseInt(inputs[j]);
            }
        }

        System.out.println(tsp(0, 1));
    }

    private static int tsp(int now, int visited) {
        if (visited == end) {
            if (money[now][0] > 0) {
                return money[now][0];
            }
            return INF;
        }

        if (dp[now][visited] != 0) {
            return dp[now][visited];
        } else {
            dp[now][visited] = INF;
        }
        for (int i = 0; i < N; i++) {
            if (money[now][i] == 0) continue;
            if ((visited & (1 << i)) != 0) continue;

            int tmp = tsp(i, visited | 1 << i);
            dp[now][visited] = Math.min(dp[now][visited], money[now][i] + tmp);
        }
        return dp[now][visited];
    }
}
