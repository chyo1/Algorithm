import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int N;
    private static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());
        sb.append((int)Math.pow(2, N) - 1 + "\n");
        hanoi(N, 1, 3, 2);
        System.out.println(sb);
    }

    private static void hanoi(int n, int start, int end, int mid) {
        if (n == 1) {
            sb.append(start + " " + end + "\n");
            return;
        }
        hanoi(n - 1, start, mid, end);
        sb.append(start + " " + end + "\n");
        hanoi(n - 1, mid, end, start);
    }
}