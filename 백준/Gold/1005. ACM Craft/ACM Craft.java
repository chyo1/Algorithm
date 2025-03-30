import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Main {
    private static int[] times;
    private static int[] cnt;
    private static int[] minTimes;
    private static List<Integer>[] lines;
    private static PriorityQueue<Integer> pq;
    private static int N, K, W;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());
        for (int i = 0; i < T; i++) {
            getInput(bf);
            minTimes = new int[N + 1];

            pq = new PriorityQueue<>((a, b) -> times[a] - times[b]);
            for (int j = 1; j <= N; j++) {
                if (cnt[j] == 0) {
                    pq.add(j);
                    minTimes[j] = 0;
                }
            }

            while (!pq.isEmpty()) {
                Integer now = pq.poll();
                for (int next : lines[now]) {
                    minTimes[next] = Math.max(minTimes[next], times[now] + minTimes[now]);
                    cnt[next]--;
                    if (cnt[next] == 0) {
                        pq.add(next);
                    }
                }
            }
            System.out.println(times[W] + minTimes[W]);
        }
    }

    private static void getInput(BufferedReader bf) throws IOException{
        String inputs[] = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        K = Integer.parseInt(inputs[1]);

        // time
        times = new int[N + 1];
        inputs = bf.readLine().split(" ");
        for (int j = 0; j < N; j++) {
            times[j + 1] = Integer.parseInt(inputs[j]);
        }

        // seq
        lines = new ArrayList[N + 1];
        for (int j = 1; j <= N; j++) {
            lines[j] = new ArrayList<>();
        }

        cnt = new int[N + 1];
        for (int j = 0; j < K; j++) {
            inputs = bf.readLine().split(" ");
            int x = Integer.parseInt(inputs[0]);
            int y = Integer.parseInt(inputs[1]);
            lines[x].add(y);
            cnt[y]++;
        }

        W = Integer.parseInt(bf.readLine());
    }
}
