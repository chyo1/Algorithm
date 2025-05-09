import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int N;
    private static int[] numbers;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        // input
        String input = bf.readLine();
        N = Integer.parseInt(input);
        numbers = new int[N];

        String[] inputLine = bf.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            int inputNum = Integer.parseInt(inputLine[i]);
            numbers[i] = inputNum;
        }

        Arrays.sort(numbers);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (findSum(i)) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    private static boolean findSum(int index) {
        int s = 0, e = N - 1;

        while (s < e) {
            if (s == index) s++;
            if (e == index) e--;

            int sum = numbers[s] + numbers[e];
            if (sum == numbers[index] && s != e) {
                return true;
            }

            if (sum < numbers[index]) {
                s++;
            } else {
                e--;
            }
        }
        return false;
    }
}
