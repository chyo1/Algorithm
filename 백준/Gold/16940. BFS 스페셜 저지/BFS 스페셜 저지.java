import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;

public class Main {
    private static int N;
    private static int[] orders;
    private static int[] priority;
    private static boolean[] visited;
    private static HashSet<Integer>[] map;
    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        orders = new int[N];
        priority = new int[N + 1];
        visited = new boolean[N + 1];
        map = new HashSet[N + 1];
        for (int i = 1; i <= N; i++) {
            map[i] = new HashSet<>();
        }

        String[] inputs;
        for (int i = 0; i < N - 1; i++) {
            inputs = bf.readLine().split(" ");
            int a = Integer.parseInt(inputs[0]);
            int b = Integer.parseInt(inputs[1]);
            map[a].add(b);
            map[b].add(a);
        }

        inputs = bf.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            orders[i] = Integer.parseInt(inputs[i]);
            priority[orders[i]] = i;
        }

        if (checkPossibility()) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }

    private static boolean checkPossibility() {
        int orderIdx = 1;
        List<Integer> checkOrder = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(
                (a, b) -> Integer.compare(priority[a], priority[b]));
        pq.add(1);
        while (!pq.isEmpty()) {
            checkOrder.clear();
            int now = pq.poll();

            visited[now] = true;
            for (int next : map[now]) {
                if (visited[next]) continue;
                checkOrder.add(next);
                pq.add(next);
                visited[next] = true;
            }

            checkOrder.sort((a, b) -> Integer.compare(priority[a], priority[b]));
            for (int seq : checkOrder) {
                if (orders[orderIdx] != seq) {
                    return false;
                }
                orderIdx++;
            }
        }
        return true;
    }
}
