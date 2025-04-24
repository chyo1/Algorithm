import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int[][] graph;
    private static int[] dis = new int[501];;
    private static final int INF = 100_000;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int TC = Integer.parseInt(bf.readLine()); // 5
        for (int i = 0; i < TC; i++) {

            // graph info
            String[] NMW = bf.readLine().split(" ");
            int N = Integer.parseInt(NMW[0]); // 500
            int M = Integer.parseInt(NMW[1]); // 2500
            int W = Integer.parseInt(NMW[2]); // 200

            graph = new int[M * 2 + W][3];

            // road
            for (int j = 0; j < M; j++) {
                String[] SET = bf.readLine().split(" ");
                int S = Integer.parseInt(SET[0]); // start
                int E = Integer.parseInt(SET[1]); // end
                int T = Integer.parseInt(SET[2]); // time + 10000

                graph[2 * j][0] = S;
                graph[2 * j][1] = E;
                graph[2 * j][2] = T;

                graph[2 * j + 1][0] = E;
                graph[2 * j + 1][1] = S;
                graph[2 * j + 1][2] = T;
            }

            // hole
            for (int j = 0; j < W; j++) {
                String[] SET = bf.readLine().split(" ");
                int S = Integer.parseInt(SET[0]); // start
                int E = Integer.parseInt(SET[1]); // end
                int T = Integer.parseInt(SET[2]); // time -

                graph[j + 2 * M][0] = S;
                graph[j + 2 * M][1] = E;
                graph[j + 2 * M][2] = -T;
            }

            // search
            boolean hasCycle = false;
            for (int j = 1; j <= N; j++) {
                hasCycle = isHasCycle(N, M, W, j);
                if (hasCycle) break;
            }
            System.out.println(hasCycle ? "YES" : "NO");
        }
    }

    private static boolean isHasCycle(int N, int M, int W, int start) {
        Arrays.fill(dis, INF);
        dis[start] = 0;

        boolean isUpdated = false;
        for (int i = 0; i < N; i++) {
            isUpdated = false;
            for (int j = 0; j < 2 * M + W; j++) {
                int S = graph[j][0];
                int E = graph[j][1];
                int T = graph[j][2];
                if (dis[S] != INF && dis[E] > dis[S] + T) {
                    dis[E] = dis[S] + T;
                    isUpdated = true;
                    if (i == N - 1) {
                        return true;
                    }
                }
            }
            if (!isUpdated) break;
        }
        return false;
    }
}
