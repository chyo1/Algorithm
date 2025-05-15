import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        char[] str1 = bf.readLine().toCharArray();
        char[] str2 = bf.readLine().toCharArray();

        int N = str1.length;
        int M = str2.length;
        int[][] dp = new int[N + 1][M + 1];

        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < M + 1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLen = dp[N][M];
        System.out.println(lcsLen);

        if (lcsLen != 0) {
            char[] lcs = new char[lcsLen];
            int r = N - 1, c = M - 1;
            int idx = lcsLen - 1;
            while (0 <= r && 0 <= c) {
                if (str1[r] == str2[c]) {
                    lcs[idx--] = str1[r];
                    r -= 1;
                    c -= 1;
                } else {
                    if (dp[r][c + 1] < dp[r + 1][c]) {
                        c -= 1;
                    } else {
                        r -= 1;
                    }
                }

            }
            System.out.println(lcs);
        }
    }
}
