import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static int N, K;
    private static int answer = 0;
    private static int[] words;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        K = Integer.parseInt(inputs[1]);

        if (K < 5) {
            System.out.println(0);
            return;
        }
        K -= 5;

        words = new int[N];
        for (int i = 0; i < N; i++) {
            String input = bf.readLine();

            int tmp = 1 << 27;
            for (int j = 4; j < input.length() - 4; j++) {
                tmp |= 1 << (input.charAt(j) - 'a');
            }
            words[i] = tmp;
        }

        int learned = 1 << 27;
        learned |= (1 << 'a' - 'a');
        learned |= (1 << 'c' - 'a');
        learned |= (1 << 'n' - 'a');
        learned |= (1 << 't' - 'a');
        learned |= (1 << 'i' - 'a');
        findMax(0, learned, 0);

        System.out.println(answer);
    }

    private static void findMax(int cnt, int learned, int idx) {
        if (cnt == K) {
            answer = Math.max(answer, getReadableCnt(learned));
            return;
        }

        for (int i = idx; i < 26; i++) {
            if ((learned & (1 << i)) == 0) {
                findMax(cnt + 1, learned | (1 << i), i + 1);
            }
        }
    }

    private static int getReadableCnt(int learned) {
        int readableCnt = 0;
        for (int i = 0; i < N; i++) {
            if ((learned & words[i]) == words[i]) {
                readableCnt++;
            }
        }
        return readableCnt;
    }
}
