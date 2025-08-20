import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    static int N, M;
    static long K;
    static int[] groups;
    static boolean[] isConnected;
    static List<int[]> stones = new ArrayList<>();
    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        K = Long.parseLong(inputs[2]);

        // save stone info
        inputs = bf.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            stones.add(new int[] {Integer.parseInt(inputs[i - 1]), i});
        }

        isConnected = new boolean[N + 1];
        Arrays.fill(isConnected, true);
        for (int i = 0; i < M; i++) {
            inputs = bf.readLine().split(" ");
            int from = Integer.parseInt(inputs[0]);
            int to = Integer.parseInt(inputs[1]);

            if (from < to || from == N)
                isConnected[from] = false;
            else
                isConnected[to] = false;
        }

        // group init
        groups = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            groups[i] = i;
        }

        // connect groups
        for (int i = 1; i < N; i++) {
            if (!isConnected[i]) continue;
            union(i, i + 1);
        }
        if (isConnected[N]) {
            union(N, 1);
        }

        stones.sort((a, b) -> Integer.compare(a[0], b[0]));

        Set<Integer> s = new HashSet<>();
        for (int i = 1; i <= N; i++) {
            find(i);
            s.add(groups[i]);
        }
        if (s.size() == 1) {
            System.out.println("YES");
            return;
        }

        s.clear();
        long stoneCnt = 0;
        for (int[] stone : stones) {
            int cnt = stone[0];
            int node = stone[1];

            if (s.contains(groups[node])) continue;

            stoneCnt += cnt;
            if (K < stoneCnt) {
                System.out.println("NO");
                return;
            }
            s.add(groups[node]);
        }

        System.out.println("YES");
    }

    static void union(int from, int to) {
        groups[find(from)] = find(to);
    }

    static int find(int node) {
        if (node == groups[node]) return node;
        return groups[node] = find(groups[node]);
    }
}
