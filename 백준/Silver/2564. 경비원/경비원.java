import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int R, C;
    public static void main(String args[]) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        R = Integer.parseInt(inputs[0]);
        C = Integer.parseInt(inputs[1]);

        int storeCnt = Integer.parseInt(bf.readLine());
        Cor[] stores = new Cor[storeCnt];
        for (int i = 0; i < storeCnt; i++) {
            inputs = bf.readLine().split(" ");
            stores[i] = new Cor(Integer.parseInt(inputs[0]) - 1, Integer.parseInt(inputs[1]));
        }

        inputs = bf.readLine().split(" ");
        Cor dong = new Cor(Integer.parseInt(inputs[0]) - 1, Integer.parseInt(inputs[1]));

        int sum = 0;
        for (Cor store : stores) {
            if (dong.dir == store.dir) {
                sum += Math.abs(dong.loc - store.loc);
            }
            else if (dong.dir / 2 == store.dir / 2) {
                // NS
                if (dong.dir / 2 == 0) {
                    sum += C + Math.min(dong.loc + store.loc, R - dong.loc + R - store.loc);
                } else {
                    sum += R + Math.min(dong.loc + store.loc, C - dong.loc + C - store.loc);
                }
            }
            else {
                int diff = Math.abs(dong.dir - store.dir);
                if (diff == 3) {
                    sum += dong.dir == 1 ? R - dong.loc + store.loc : dong.loc + R - store.loc;
                } else {
                    if (dong.dir == 0 || store.dir == 0) {
                        sum += dong.loc + store.loc;
                    } else if (dong.dir == 1 || store.dir == 1) {
                        if (dong.dir == 2 || store.dir == 2)
                            sum += dong.dir == 1 ? dong.loc + C - store.loc : C - dong.loc + store.loc;
                        else
                            sum += dong.dir == 1 ? R - dong.loc + C - store.loc : C - dong.loc + R - store.loc;
                    } else if (dong.dir == 3 || store.dir == 3) {
                        sum += dong.dir == 3 ? C - dong.loc + R - store.loc : R - dong.loc + C - store.loc;
                    }
                }
            }
        }
        System.out.println(sum);
    }

    static class Cor {
        int dir;
        int loc;

        public Cor(int dir, int loc) {
            this.dir = dir;
            this.loc = loc;
        }
    }
}
