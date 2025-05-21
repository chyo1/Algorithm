import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    private static int N;
    private static long[] values;

    private static long[] minValues = new long[3];
    private static long answer = 4_000_000_000L;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        values = new long[N];
        String[] inputs = bf.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            values[i] = Integer.parseInt(inputs[i]);
        }

        Arrays.sort(values);
        for (int i = 0; i < N; i++) {
            getZero(i);
        }

        Arrays.sort(minValues);
        System.out.printf("%d %d %d\n", minValues[0], minValues[1], minValues[2]);
    }

    private static void getZero(int idx) {
        int start = idx == 0 ? 1 : 0;
        int end = idx == N - 1 ? N - 2 : N - 1;

        while (start < end) {

            long nowSum = values[idx] + values[start] + values[end];

            if (Math.abs(nowSum) < answer) {
                answer = Math.abs(nowSum);
                minValues[0] = values[idx];
                minValues[1] = values[start];
                minValues[2] = values[end];
            }
            if (start < N && Math.abs(values[idx] + values[start + 1] + values[end])
                    < Math.abs(values[idx] + values[start] + values[end - 1])) {
                start++;
            } else {
                end--;
            }

            if (start < N && start == idx) {
                start++;
            }
            if (0 < end && end == idx) {
                end--;
            }
        }
    }
}
