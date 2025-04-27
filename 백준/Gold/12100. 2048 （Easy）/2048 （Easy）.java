import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int[][] board;
    private static final int LEFT = 0;
    private static final int RIGHT = 1;
    private static final int UP = 2;
    private static final int DOWN = 3;
    private static int N;
    private static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        // input
        N = Integer.parseInt(bf.readLine());
        board = new int[N][N];

        for (int i = 0; i < N; i++) {
            String[] inputLine = bf.readLine().split(" ");

            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(inputLine[j]);
            }
        }

        move4Ways(0);
        System.out.println(answer);
    }

    private static void move4Ways(int time) {
        if (time == 5) {
            findMaxValue();
            return;
        }

        int[][] copy = new int[board.length][];
        for (int i = 0; i < copy.length; i++) {
            copy[i] = board[i].clone();
        }

        for (int i = 0; i < 4; i++) {
            moveBoard(i);
            move4Ways(time + 1);

            for (int j = 0; j < copy.length; j++) {
                board[j] = copy[j].clone();
            }
        }
    }

    private static void findMaxValue() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer = Math.max(answer, board[i][j]);
            }
        }
    }

    private static void moveBoard(int dir) {
        for (int i = 0; i < N; i++) {
            if (dir == LEFT) {
                moveLeft(i);
            } else if (dir == RIGHT) {
                moveRight(i);
            } else if (dir == UP) {
                moveUp(i);
            } else {
                moveDown(i);
            }
        }
    }

    private static void moveLeft(int i) {
        int[] newLine = new int[N];
        int idx = 0;
        int prev = 0;

        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;

            if (prev == 0) {
                prev = board[i][j];
            } else if (prev == board[i][j]) {
                newLine[idx++] = prev * 2;
                prev = 0;
            } else {
                newLine[idx++] = prev;
                prev = board[i][j];
            }
        }
        if (prev != 0) {
            newLine[idx] = prev;
        }
        for (int j = 0; j < N; j++) {
            board[i][j] = newLine[j];
        }
    }

    private static void moveRight(int i) {
        int[] newLine = new int[N];
        int idx = N - 1;
        int prev = 0;

        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] == 0) continue;

            if (prev == 0) {
                prev = board[i][j];
            } else if (prev == board[i][j]) {
                newLine[idx--] = prev * 2;
                prev = 0;
            } else {
                newLine[idx--] = prev;
                prev = board[i][j];
            }
        }
        if (prev != 0) {
            newLine[idx] = prev;
        }
        for (int j = N - 1; j >= 0; j--) {
            board[i][j] = newLine[j];
        }
    }

    private static void moveUp(int j) {
        int[] newLine = new int[N];
        int idx = 0;
        int prev = 0;

        for (int i = 0; i < N; i++) {
            if (board[i][j] == 0) continue;

            if (prev == 0) {
                prev = board[i][j];
            } else if (prev == board[i][j]) {
                newLine[idx++] = prev * 2;
                prev = 0;
            } else {
                newLine[idx++] = prev;
                prev = board[i][j];
            }
        }
        if (prev != 0) {
            newLine[idx] = prev;
        }
        for (int i = 0; i < N; i++) {
            board[i][j] = newLine[i];
        }
    }

    private static void moveDown(int j) {
        int[] newLine = new int[N];
        int idx = N - 1;
        int prev = 0;

        for (int i = N - 1; i >= 0; i--) {
            if (board[i][j] == 0) continue;

            if (prev == 0) {
                prev = board[i][j];
            } else if (prev == board[i][j]) {
                newLine[idx--] = prev * 2;
                prev = 0;
            } else {
                newLine[idx--] = prev;
                prev = board[i][j];
            }
        }
        if (prev != 0) {
            newLine[idx] = prev;
        }
        for (int i = N - 1; i >= 0; i--) {
            board[i][j] = newLine[i];
        }
    }
}
