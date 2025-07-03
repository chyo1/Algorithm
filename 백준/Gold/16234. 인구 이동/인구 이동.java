import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;

public class Main {
    private static int N, L, R;
    private static int[][] A, union;
    private static Map<Integer, Integer> map = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        L = Integer.parseInt(inputs[1]);
        R = Integer.parseInt(inputs[2]);

        A = new int[N][N];
        union = new int[N][N];

        for (int i = 0; i < N; i++) {
            inputs = bf.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                A[i][j] = Integer.parseInt(inputs[j]);
            }
        }

        int cnt = 0;
        while (true) {
            for (int i = 0; i < N; i++) {
                Arrays.fill(union[i], 0);
            }
            map.clear();

            makeUnion();
            if (!movePeople()) break;
            cnt++;
        }
        System.out.println(cnt);
    }

    private static void makeUnion() {
        int groupNum = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (union[i][j] == 0) {
                    bfs(i, j, groupNum);
                    groupNum++;
                }
            }
        }
    }

    private static void bfs(int r, int c, int groupNum) {
        int[][] mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        Queue<Cor> q = new ArrayDeque<>();
        q.add(new Cor(r, c));
        union[r][c] = groupNum;

        int sum = A[r][c];
        int cnt = 1;

        while (!q.isEmpty()) {
            Cor now = q.poll();

            for (int i = 0; i < 4; i++) {
                int nr = now.r + mv[i][0];
                int nc = now.c + mv[i][1];

                if (nr < 0 || nc < 0 || N <= nr || N <= nc || union[nr][nc] != 0) continue;

                int diff = Math.abs(A[now.r][now.c] - A[nr][nc]);
                if (L <= diff && diff <= R) {
                    q.add(new Cor(nr, nc));
                    union[nr][nc] = groupNum;
                    sum += A[nr][nc];
                    cnt++;
                }
            }
        }

        map.put(groupNum, sum / cnt);
    }

    static class Cor {
        int r;
        int c;

        public Cor(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    private static boolean movePeople() {
        boolean isMoved = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int people = map.get(union[i][j]);
                if (A[i][j] != people) isMoved = true;
                A[i][j] = people;
            }
        }
        return isMoved;
    }

}