import java.util.*;
import java.io.*;

class Main
{
	static int[][] map;
	static int N, M, R;
    public static void main(String args[]) throws Exception
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        N = Integer.parseInt(inputs[0]);
        M = Integer.parseInt(inputs[1]);
        R = Integer.parseInt(inputs[2]);
         
        map = new int[N][M];
        for (int i = 0; i < N; i++) {
        	inputs = bf.readLine().split(" ");
        	for (int j = 0; j < M; j++) {
        		map[i][j] = Integer.parseInt(inputs[j]);
        	}
        }
        
        int[][] mv = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rl = 0;
        int rr = N - 1;
        int cl = 0;
        int cr = M - 1;
        
        while (rl < rr && cl < cr) {
        	int r = rl;
            int c = cl;
            boolean flag = false;
            List<Integer> list = new ArrayList<>();
            int idx = 0;
            
	    	while (idx < 4) {
	    		if (!(rl <= r && r <= rr && cl <= c && c <= cr) || (flag && r == rl && c == cl)) {
	        		r -= mv[idx][0];
	        		c -= mv[idx][1];
	        		idx++;
	        		if (idx == 4) break;
	    		}
	    		else
	    			list.add(map[r][c]);
	    		      		
	    		r += mv[idx][0];
	    		c += mv[idx][1];
	    		flag = true;
	    	}
	    	
	    	int len = list.size();
	    	r = rl;
	    	c = cl;
	    	idx = 0;
	    	flag = false;
	    	int cnt = 0;
    		while (idx < 4) {
        		if (!(rl <= r && r <= rr && cl <= c && c <= cr) || (flag && r == rl && c == cl)) {
            		r -= mv[idx][0];
            		c -= mv[idx][1];
            		idx++;
            		if (idx == 4) break;
        		}
        		
        		else
        			map[r][c] = list.get((cnt++ + R) % len);
        		      		
        		r += mv[idx][0];
        		c += mv[idx][1];
        		flag = true;
        	}
	    	rl++; rr--;
	    	cl++; cr--;
        }
      
        print();

    }
    private static void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}