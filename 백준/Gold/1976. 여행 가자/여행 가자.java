import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    private static int N, M;
    private static int[] parents;

    private static void union(int a, int b) {
        parents[b] = a;
    }

    private static int find(int a) {
        if (a == parents[a])
            return a;
        return parents[a] = find(parents[a]);
    }

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String input = bf.readLine();
        N = Integer.parseInt(input);
        input = bf.readLine();
        M = Integer.parseInt(input);

        // init
        parents = new int[N];
        for (int i = 0; i < N; i++)
            parents[i] = i;

        for (int i = 0; i < N; i++) {
            String[] tmp = bf.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                int isConnected = Integer.parseInt(tmp[j]);
                if (isConnected == 1 && find(i) != find(j))
                    union(find(i), find(j));
            }
        }

        String[] paths = bf.readLine().split(" ");
        for (int i = 0; i < M - 1; i++) {
            int a = Integer.parseInt(paths[i]) - 1;
            int b = Integer.parseInt(paths[i + 1]) - 1;
            if (find(a) != find(b)) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
