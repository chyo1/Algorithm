import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    private static int[] group;
    private static int V, E;
    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        V = Integer.parseInt(inputs[0]);
        E = Integer.parseInt(inputs[1]);
        group = new int[V];

        for (int i = 0; i < V; i++) {
            group[i] = i;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> Integer.compare(a[2], b[2])
        );
        for (int i = 0; i < E; i++) {
            inputs = bf.readLine().split(" ");
            int A = Integer.parseInt(inputs[0]) - 1;
            int B = Integer.parseInt(inputs[1]) - 1;
            int C = Integer.parseInt(inputs[2]);
            pq.add(new int[]{A, B, C});
        }

        long sum = 0;
        while (!pq.isEmpty()) {
            int[] now = pq.poll();
            if (find(now[0]) == find(now[1])) continue;

            union(now[0], now[1]);
            sum += now[2];
        }

        System.out.println(sum);
    }

    private static int find(int a) {
        if (group[a] == a) {
            return a;
        }
        return group[a] = find(group[a]);
    }

    private static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            group[rootB] = rootA;
        }
    }
}
