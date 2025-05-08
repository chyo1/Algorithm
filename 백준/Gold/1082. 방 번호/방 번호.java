import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int N, money;
    private static int[] prices;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        // input
        String input = bf.readLine();
        N = Integer.parseInt(input);
        prices = new int[N];

        String[] inputLine = bf.readLine().split(" ");
        for (int i = 0; i < N; i++) {
           prices[i] = Integer.parseInt(inputLine[i]);
        }
        money = Integer.parseInt(bf.readLine());

        getMax();
    }

    private static void getMax() {
        int minNoZero = 51;
        int minNoZeroIdx = 0;
        int minWithZero = 51;
        int minWithZeroIdx = 0;

        for (int i = 0; i < N; i++) {
            if (i != 0 && prices[i] < minNoZero) {
                minNoZero = prices[i];
                minNoZeroIdx = i;
            }
            if (prices[i] < minWithZero) {
                minWithZero = prices[i];
                minWithZeroIdx = i;
            }
        }
        if (money < minNoZero) {
            System.out.println(0);
            return;
        }

        int[] arr = new int[51];
        int size = 0;

        arr[size++] = minNoZeroIdx;
        money -= minNoZero;
        while (minWithZero <= money) {
            arr[size++] = minWithZeroIdx;
            money -= minWithZero;
        }

        for (int i = 0; i < size; i++) {
            for (int j = N - 1; j > arr[i]; j--) {
                if (money + prices[arr[i]] >= prices[j]) {
                    money += prices[arr[i]];
                    money -= prices[j];
                    arr[i] = j;
                    break;
                }
            }
        }


        for (int i = 0; i < size; i++) {
            System.out.print(arr[i]);
        }
    }
}
