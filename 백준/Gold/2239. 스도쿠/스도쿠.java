import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static final int SIZE = 9;
    private static int[][] sudoku = new int[SIZE][SIZE];
    private static boolean[][] row = new boolean[SIZE + 1][SIZE + 1];
    private static boolean[][] col = new boolean[SIZE + 1][SIZE + 1];
    private static boolean[][][] box = new boolean[SIZE / 3][SIZE / 3][SIZE + 1];

    private static List<Integer[]> arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < SIZE; i++) {
            String inputs = bf.readLine();
            for (int j = 0; j < SIZE; j++) {
                int n = inputs.charAt(j) - '0';
                if (n != 0) {
                    row[i][n] = true;
                    col[j][n] = true;
                    box[i / 3][j / 3][n] = true;
                }
                else
                    arr.add(new Integer[]{i, j});
                sudoku[i][j] = n;
            }
        }

        fillSudoku(0);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print(sudoku[i][j]);
            }
            System.out.println();
        }
    }

    private static boolean fillSudoku(int idx) {
        if (arr.size() <= idx) return true;
        Integer[] now = arr.get(idx);

        int i = now[0], j = now[1];
        for (int k = 1; k <= SIZE; k++) {
            if (row[i][k] || col[j][k] || box[i / 3][j / 3][k]) continue;
            row[i][k] = true;
            col[j][k] = true;
            box[i / 3][j / 3][k] = true;

            sudoku[i][j] = k;
            if (fillSudoku(idx + 1)) return true;

            row[i][k] = false;
            col[j][k] = false;
            box[i / 3][j / 3][k] = false;

        }
        return false;
    }
}
