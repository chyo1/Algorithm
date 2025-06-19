import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int N, C;
    private static int[] loc;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        C = Integer.parseInt(inputs[1]);

        loc = new int[N];
        for (int i = 0; i < N; i++) {
            loc[i] = Integer.parseInt(bf.readLine());
        }
        Arrays.sort(loc);


        int l = 0;
        int r = loc[N - 1];

        while (l <= r) {
            int mid = (l + r) / 2;

            int cnt = 1;
            int bef = 0;
            for (int i = 0; i < N; i++) {
                if (loc[i] - loc[bef] >= mid) {
                    cnt++;
                    bef = i;
                }
            }
            if (cnt < C) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        System.out.println(l - 1);
    }

}
// 1 2 4 8 9