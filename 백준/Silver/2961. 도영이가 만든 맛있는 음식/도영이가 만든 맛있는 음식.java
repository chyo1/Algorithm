import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int[][] materials;
    static int N, minDiff;
    static boolean[] visited;
    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        materials = new int[N][2];
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            String[] inputs = bf.readLine().split(" ");
            materials[i][0] = Integer.parseInt(inputs[0]);
            materials[i][1] = Integer.parseInt(inputs[1]);
        }
        minDiff = 1_000_000_001;
        getCombi(0, 0);
        System.out.println(minDiff);
    }

    private static void getCombi(int now, int size) {
        for (int i = 0; i < N; i++) {
            if (size == 0 && N / 2 < i) return;
            if (!visited[i]) {
                visited[i] = true;
                calDiff();
                getCombi(i, size + 1);
                visited[i] = false;
            }
        }
    }

    private static void calDiff() {
        int sum = 0;
        int mul = 1;
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                mul *= materials[i][0];
                sum += materials[i][1];
            }
        }
        minDiff = Math.min(Math.abs(sum - mul), minDiff);
    }
}
