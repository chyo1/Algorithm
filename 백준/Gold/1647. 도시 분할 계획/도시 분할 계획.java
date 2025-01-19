import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    private static int N, M;
    private static int[] parents;
    private static int lineCount = 0;
    private static int totalCost = 0;

    private static void union(int a, int b) {
        parents[b] = a;
    }

    private static int find(int a) {
        if (a == parents[a])
            return a;
        return parents[a] = find(parents[a]);
    }

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2]-b[2]);
        for (int i = 0; i < M; i++) {
            String[] tmp = bf.readLine().split(" ");
            int start = Integer.parseInt(tmp[0]);
            int end = Integer.parseInt(tmp[1]);
            int cost = Integer.parseInt(tmp[2]);

            pq.add(new int[]{start, end, cost});
        }

        // init
        parents = new int[N + 1];
        for (int i = 1; i <= N; i++)
            parents[i] = i;

        //
        while (lineCount < N - 2) {
            int[] poll = pq.poll();
            int a = poll[0], b = poll[1], cost = poll[2];
            int p1 = find(a), p2 = find(b);
            if (p1 != p2) {
                union(p1, p2);
                totalCost += cost;
                lineCount++;
            }
        }

        System.out.println(totalCost);
    }
}
