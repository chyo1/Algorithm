import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class Main {
    static int N, M, groupNum = 1;
    static int[][] map;
    static boolean[][] visited;
    static int[] root;
    static List<int[]> paths = new ArrayList<>();

    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);

        map = new int[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            inputs = bf.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(inputs[j]);
            }
        }

        // 섬 찾기
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    makeGroup(i, j);
                    groupNum++;
                }
            }
        }

        // 섬 간 거리 찾기
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0 && !visited[i][j]) {
                    visited[i][j] = true;
                    findLen(i, j, map[i][j]);
                }
            }
        }

        root = new int[groupNum];
        for (int i = 0; i < groupNum; i++) {
            root[i] = i;
        }
        paths.sort((a, b) -> Integer.compare(a[2], b[2]));
        int ans = 0;
        for (int[] path : paths) {
            if (find(path[0]) == find(path[1]) || path[2] < 2) continue;
            ans += path[2];
            union(path[0], path[1]);
        }

        for (int i = 1; i < groupNum; i++) {
            find(i);
        }
        int group = root[1];
        for (int i = 1; i < groupNum; i++) {
            find(i);
            if (group != root[i]) {
                ans = -1;
                break;
            }
        }
        System.out.println(ans);
    }

    private static void findLen(int r, int c, int num) {
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int nr = r;
        int nc = c;
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            nr = r;
            nc = c;
            while (true) {
                nr += mv[i][0];
                nc += mv[i][1];

                if (nr < 0 || nc < 0 || N <= nr || M <= nc || map[nr][nc] == num) break;
                if (map[nr][nc] != num && map[nr][nc] != 0) { // 다른 섬에 도착
                    paths.add(new int[]{num, map[nr][nc], cnt});
                    break;
                }
                cnt++;
            }
        }
    }

    private static void makeGroup(int r, int c) {
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r, c});
        map[r][c] = groupNum;
        while (!q.isEmpty()) {
            int[] now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now[0] + mv[i][0];
                int nc = now[1] + mv[i][1];
                if (nr < 0 || nc < 0 || N <= nr || M <= nc || visited[nr][nc] ) continue;
                visited[nr][nc] = true;
                if (map[nr][nc] == 1) {
                    map[nr][nc] = groupNum;
                    q.add(new int[]{nr, nc});
                }
            }
        }
    }
    static void union(int a, int b) {
        root[find(b)] = find(a);
    }

    private static int find(int a) {
        if (root[a] == a) return a;
        return root[a] = find(root[a]);
    }
}
