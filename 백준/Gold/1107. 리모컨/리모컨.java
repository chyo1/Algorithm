import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    private static boolean[] broken = new boolean[10];

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int start = 100;
        int target = Integer.parseInt(bf.readLine());
        int M = Integer.parseInt(bf.readLine());

        Arrays.fill(broken, false);
        if (M != 0) {
            String[] inputs = bf.readLine().split(" ");
            for (int i = 0; i < M; i++) {
                broken[Integer.parseInt(inputs[i])] = true;
            }
        }

        if (start == target) {
            System.out.println(0);
            return;
        }

        int minClick = Math.abs(target - start);
        for (int i = 0; i < 1_000_000; i++) {
            String s = String.valueOf(i);
            int len = s.length();

            boolean isBroken = false;
            for (int j = 0; j < len; j++) {
                if (broken[s.charAt(j) - '0']) {
                    isBroken = true;
                    break;
                }
            }
            if (!isBroken) {
                minClick = Math.min(minClick, Math.abs(target - i) + len);
            }
        }

        System.out.println(minClick);

    }
}