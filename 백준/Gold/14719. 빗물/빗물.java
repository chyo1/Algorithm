import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int H, W;
    private static int[] blocks, water;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] input = bf.readLine().split(" ");
        H = Integer.parseInt(input[0]);
        W = Integer.parseInt(input[1]);

        blocks = new int[W];
        water = new int[W];
        String[] blockInput = bf.readLine().split(" ");
        for (int i = 0; i < W; i++) {
            blocks[i] = Integer.parseInt(blockInput[i]);
            water[i] = Integer.parseInt(blockInput[i]);
        }

        int sum = 0;
        for (int i = 0; i < W; i++) {
            int l = 0, r = 0;
            for (int j = 0; j < i; j++)
                l = Math.max(l, blocks[j]);
            for (int j = i; j < W; j++)
                r = Math.max(r, blocks[j]);

            if (blocks[i] < l && blocks[i] < r)
                sum += Math.min(l, r) - blocks[i];
        }

        System.out.println(sum);
    }
}
