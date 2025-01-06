import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Main {
    static int MAX_VALUE = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // input
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[][] path = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(path[i], MAX_VALUE);
            path[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            String[] tokens = br.readLine().split(" ");
            int start = Integer.parseInt(tokens[0]) - 1;
            int end = Integer.parseInt(tokens[1]) - 1;
            int cost = Integer.parseInt(tokens[2]);
            path[start][end] = Math.min(cost, path[start][end]);
        }

        String[] tokens = br.readLine().split(" ");
        int start = Integer.parseInt(tokens[0]) - 1;
        int end = Integer.parseInt(tokens[1]) - 1;

        int[] before = new int[n];
        int[] distance = new int[n];
        Arrays.fill(distance, MAX_VALUE);
        boolean[] visited = new boolean[n];

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Integer.compare(distance[a], distance[b]));
        distance[start] = 0;
        before[start] = start;
        pq.add(start);

        while (!pq.isEmpty()) {
            int now = pq.poll();

            if (visited[now]) continue;
            visited[now] = true;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && path[now][i] != MAX_VALUE && distance[now] + path[now][i] < distance[i]) {
                    distance[i] = distance[now] + path[now][i];
                    before[i] = now;
                    pq.add(i);
                }
            }
        }

        LinkedList<Integer> way = new LinkedList<>();
        way.addFirst(end + 1);
        while (true) {
            int now = way.getFirst() - 1;
            if (now == start) break;

            way.addFirst(before[now] + 1);
        }

        System.out.println(distance[end]);
        System.out.println(way.size());
        for (int w : way)
            System.out.print(w + " ");
    }
}
