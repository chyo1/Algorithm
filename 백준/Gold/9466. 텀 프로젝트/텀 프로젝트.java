import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int T, N;
    private static int[] choices;
    private static boolean[] finished;
    private static boolean[] visited;
    private static int count;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(bf.readLine());

        for (int i = 0; i < T; i++) {
            N = Integer.parseInt(bf.readLine());

            finished = new boolean[N];
            visited = new boolean[N];

            choices = new int[N];
            String[] inputs = bf.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                choices[j] = Integer.parseInt(inputs[j]) - 1;
            }

            // 팀이 없는 학생들의 팀 찾기
            count = 0;
            for (int j = 0; j < N; j++) {
                if (!visited[j]) {
                    makeTeam(j);
                }
            }
            System.out.println(N - count);
        }
    }

    private static void makeTeam(int now) {
        visited[now] = true;

        int next = choices[now];
        if (!visited[next]) {
            makeTeam(next);
        } else if (!finished[next]) {
            for (int i = next; i != now; i = choices[i]) {
                count++;
            }
            count++; // now 자신 포함
        }
        finished[now] = true;
    }
}
