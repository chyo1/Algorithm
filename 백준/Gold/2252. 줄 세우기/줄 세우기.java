import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
    private static int N, M;
    private static List<Integer> orders[];
    private static int[] cnt;
    private static boolean[] visited;
    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] NM = bf.readLine().split(" ");
        N = Integer.parseInt(NM[0]);
        M = Integer.parseInt(NM[1]);

        visited = new boolean[N + 1];
        cnt = new int[N + 1];
        orders = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            orders[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            String[] AB = bf.readLine().split(" ");
            int A = Integer.parseInt(AB[0]);
            int B = Integer.parseInt(AB[1]);

            orders[A].add(B);
            orders[B].add(A);
            cnt[B]++;
        }

        printLine();
    }

    private static void printLine() {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (cnt[i] == 0) {
                q.add(i);
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            visited[now] = true;
            System.out.print(now + " ");

            for (int connects : orders[now]) {
                if (!visited[connects]) {
                    cnt[connects]--;
                    if (cnt[connects] == 0) {
                        q.add(connects);
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                System.out.print(i + " ");
            }
        }
    }
}
