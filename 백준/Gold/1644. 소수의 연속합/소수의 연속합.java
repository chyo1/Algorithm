import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static List<Integer> primes = new ArrayList<>();
    private static boolean[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        int N;
        N = Integer.parseInt(bf.readLine());
        nums = new boolean[N + 1];
        findPrime(N);

        int start = 0;
        int end = 0;
        int size = primes.size();

        int sum = 0;
        while (start < size && end < size) {
            if (sum <= N) {
                sum += primes.get(end++);
            } else {
                sum -= primes.get(start++);
            }

            if (sum == N) answer++;
        }
        if (N < sum) {
            while (start < size && N < sum) {
                sum -= primes.get(start++);
            }
            if (sum == N)
                answer++;
        }

        System.out.println(answer);
    }

    private static void findPrime(int n) {
        for (int i = 2; i <= n; i++) {
            if (nums[i]) continue;

            primes.add(i);
            for (int j = i; j <= n; j += i) {
                nums[j] = true;
            }
        }
    }
}
