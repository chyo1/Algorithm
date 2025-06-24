import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int N, S;
    private static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");

        N = Integer.parseInt(inputs[0]);
        S = Integer.parseInt(inputs[1]);

        inputs = bf.readLine().split(" ");
        nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(inputs[i]);
        }

        int minLen = N + 1;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            if (S <= sum) {
                while (S <= sum - nums[start]) {
                    sum -= nums[start];
                    start++;
                }
                minLen = Math.min(minLen, i - start + 1);
            }
        }
        if (minLen > N)
            minLen = 0;
        System.out.println(minLen);
    }
}