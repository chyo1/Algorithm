import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class Main {
    private static int N, K;
    private static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");

        N = Integer.parseInt(inputs[0]);
        K = Integer.parseInt(inputs[1]);
        Queue<Integer> q = new ArrayDeque<>();

        int[] logs = new int[100_001];
        Arrays.fill(logs, -1);

        q.add(N);
        logs[N] = -2;
        while (!q.isEmpty()) {
            Integer now = q.poll();
            if (now == K) break;
            if (now + 1 <= 100_000 && logs[now + 1] == -1) {
                logs[now + 1] = now;
                q.add(now + 1);
            }

            if (0 <= now - 1 && logs[now - 1] == -1) {
                logs[now - 1] = now;
                q.add(now - 1);
            }

            if (now * 2 <= 100_000 && logs[now * 2] == -1) {
                logs[now * 2] = now;
                q.add(now * 2);
            }
        }
        System.out.println(getCount(logs, K));
        printLog(logs, K);
    }

    private static int getCount(int[] logs, int now) {
        if (logs[now] == -2) return 0;
        return getCount(logs, logs[now]) + 1;
    }

    private static void printLog(int[] logs, int now) {
        if (now == -2) return;
        int bef = logs[now];
        printLog(logs, bef);
        System.out.print(now + " ");
    }
}