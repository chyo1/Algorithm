import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    private static int N, K;
    private static ArrayList<int[]> jewelsInfo = new ArrayList<>();
    private static ArrayList<Integer> bags = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        // input
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        K = Integer.parseInt(inputs[1]);

        for (int i = 0; i < N; i++) {
            String[] inputLine = bf.readLine().split(" ");
            int m = Integer.parseInt(inputLine[0]);
            int v = Integer.parseInt(inputLine[1]);
            jewelsInfo.add(new int[]{m, v});
        }

        for (int i = 0; i < K; i++) {
            Integer c = Integer.parseInt(bf.readLine());
            bags.add(c);
        }

        jewelsInfo.sort((a, b) -> {
            if (a[0] == b[0])
                return Integer.compare(b[1], a[1]);
            return Integer.compare(a[0], b[0]);
        });
        bags.sort(Comparator.naturalOrder());
        System.out.println(getMaxPrice());
    }

    private static long getMaxPrice() {
        int gIdx = 0;
        long sum = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < bags.size(); i++) {
            while (gIdx < jewelsInfo.size() && jewelsInfo.get(gIdx)[0] <= bags.get(i)) {
                pq.add(jewelsInfo.get(gIdx++)[1]);
            }
            if (!pq.isEmpty()) {
                sum += pq.poll();
            }
        }
        return sum;
    }
}
