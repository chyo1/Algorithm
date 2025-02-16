import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int N, C;
    private static int[] weights;
    private static List<Integer> left = new ArrayList<>();;
    private static List<Integer> right = new ArrayList<>();;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);

        weights = new int[N];
        String[] blockInput = bf.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            weights[i] = Integer.parseInt(blockInput[i]);
        }

        combi(left, 0, N / 2, 0);
        combi(right, N / 2, N, 0);

        int cnt = 0;

        right.sort(null);
        int rSize = right.size() - 1;
        for (int i = 0; i < left.size(); i++) {
            int idx = findUpperBound(0, rSize, left.get(i));
            cnt += idx + 1;
        }
        System.out.println(cnt);
    }

    private static int findUpperBound(int start, int end, Integer value) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (right.get(mid) <= C - value)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }

    private static void combi(List<Integer> list, int start, int end, int sum) {
        if (sum > C) return;
        if (start == end) {
            list.add(sum);
            return;
        }
        combi(list, start + 1, end, sum);
        combi(list, start + 1, end, sum + weights[start]);
    }
}
