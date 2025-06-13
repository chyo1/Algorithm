import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int[] num;
    private static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s = bf.readLine();
        int T = Integer.parseInt(s);

        List<Grade> grades = new ArrayList<>();
        for (int t = 0; t < T; t++) {
            n = Integer.parseInt(bf.readLine());
            for (int i = 0; i < n; i++) {
                String[] inputs = bf.readLine().split(" ");
                int doc = Integer.parseInt(inputs[0]);
                int meet = Integer.parseInt(inputs[1]);

                grades.add(new Grade(doc, meet));
            }
            grades.sort((a, b) ->
                    Integer.compare(a.document, b.document));

            int cnt = 1;
            int rate = grades.get(0).meeting;
            for (int i = 1; i < n; i++) {
                if (rate > grades.get(i).meeting) {
                    cnt++;
                    rate = grades.get(i).meeting;
                }
            }

            System.out.println(cnt);
            grades.clear();
        }
    }

    private static class Grade {
        int meeting;
        int document;

        public Grade(int meeting, int document) {
            this.meeting = meeting;
            this.document = document;
        }
    }
}
