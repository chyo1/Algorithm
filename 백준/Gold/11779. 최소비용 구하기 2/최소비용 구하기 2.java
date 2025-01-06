import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int MAX_VALUE = 1_000_000_000;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] path = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(path[i], MAX_VALUE);
            path[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int start = sc.nextInt() - 1;
            int end = sc.nextInt() - 1;
            int cost = sc.nextInt();
            path[start][end] = Math.min(cost, path[start][end]);
        }

        int start = sc.nextInt() - 1;
        int end = sc.nextInt() - 1;

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
