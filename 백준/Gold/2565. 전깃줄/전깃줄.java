import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N;
    static int[][] wires;
    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        wires = new int[N][2];
        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            int a = Integer.parseInt(inputs[0]);
            int b = Integer.parseInt(inputs[1]);
            wires[i][0] = a;
            wires[i][1] = b;
        }

        Arrays.sort(wires, (a, b) -> Integer.compare(a[0], b[0]));
        int[] dp = new int[N];
        int maxValue = 0;
        for (int i = 0; i < N; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (wires[j][1] < wires[i][1]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                    maxValue = Math.max(dp[i], maxValue);
                }
            }
        }
        System.out.println(N - maxValue);

    }
}
