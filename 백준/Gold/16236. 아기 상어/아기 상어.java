import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    private static int N;
    private static int size = 2;
    private static int[][] map;
    private static int[][] mv = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());
        map = new int[N][N];
        int[] startLoc = new int[2];

        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(inputs[j]);
                if (map[i][j] == 9) {
                    startLoc[0] = i;
                    startLoc[1] = j;
                    map[i][j] = 0;
                }
            }
        }
        System.out.println(findMaxTime(startLoc, 0, 0));
    }

    private static int findMaxTime(int[] nowLoc, int eatCnt, int sec) {
        if (eatCnt == size) {
            eatCnt = 0;
            size++;
        }
        int[] next = findNextLoc(nowLoc);
        if (next[0] == -1) {
            return sec;
        }

        map[next[0]][next[1]] = 0;
        sec += next[2];
        return findMaxTime(next, eatCnt + 1, sec);
    }

    private static int[] findNextLoc(int[] nowLoc) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> {
                    if (a[2] == b[2]) {
                        if (a[0] == b[0]) {
                            return Integer.compare(a[1], b[1]);
                        }
                        return Integer.compare(a[0], b[0]);
                    }
                    return Integer.compare(a[2], b[2]);
                }
        );
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][N];

        q.add(new int[]{nowLoc[0], nowLoc[1], 0});
        visited[nowLoc[0]][nowLoc[1]] = true;

        while (!q.isEmpty()) {
            int[] now = q.poll();

            for (int i = 0; i < 4; i++) {
                int x = now[0] + mv[i][0];
                int y = now[1] + mv[i][1];

                if (x < 0 || y < 0 || N <= x || N <= y || visited[x][y]) continue;

                if (map[x][y] == 0 || map[x][y] == size) {
                    q.add(new int[]{x, y, now[2] + 1});
                }
                else if (map[x][y] < size) {
                    pq.add(new int[]{x, y, now[2] + 1});
                }
                visited[x][y] = true;
            }
        }
        if (pq.isEmpty()) {
            return new int[]{-1, -1, 0};
        }
        return pq.poll();
    }
}
