import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int[][] times;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());

        times = new int[N][2];
        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            times[i][0] = Integer.parseInt(inputs[0]);
            times[i][1] = Integer.parseInt(inputs[1]);
        }

        Arrays.sort(times, (a, b) -> {
            if (a[1] == b[1]) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[1], b[1]);
        });

        int finTime = times[0][1];
        int cnt = 1;
        for (int i = 1; i < N; i++) {
            if (finTime <= times[i][0]) {
                finTime = times[i][1];
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
