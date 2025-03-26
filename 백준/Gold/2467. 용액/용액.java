import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        int[] values = new int[N];

        String[] inputs = bf.readLine().split(" ");
        int idx = 0;
        for (String input : inputs) {
            values[idx++] = Integer.parseInt(input);
        }

        int start = 0;
        int end = N - 1;
        int minSum = Integer.MAX_VALUE;
        int[] minSumIdx = new int[2];

        while (start < end) {
            int sum = values[start] + values[end];
            if (Math.abs(sum) < minSum) {
                minSum = Math.abs(sum);
                minSumIdx[0] = values[start];
                minSumIdx[1] = values[end];
            }
            if (0 < sum) {
                end--;
            } else {
                start++;
            }
        }
        System.out.printf("%d %d", minSumIdx[0], minSumIdx[1]);

    }
}
