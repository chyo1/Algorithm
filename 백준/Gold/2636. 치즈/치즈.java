import java.util.*;
import java.io.*;

class Main {
	static int[][] map;

    static int N, M;
    
    static int[] dr = {-1, 1, 0, 0}; // up, down
    static int[] dc = {0, 0, -1, 1}; // left, right
    
    public static void main(String args[]) throws Exception {
    	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    		
    	String[] inputs = bf.readLine().split(" ");
		N = Integer.parseInt(inputs[0]);
		M = Integer.parseInt(inputs[1]);
		
		map = new int[N][M];
		
		int cheese = 0;
		for (int i = 0; i < N; i++) {
			inputs = bf.readLine().split(" ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(inputs[j]);
				if (map[i][j] == 1) cheese++;
			}
		}
		
		int time = 0;
		int meltedCheese = 0;
		while (true) {
			time++;
			meltedCheese = melting(0, 0);
			cheese -= meltedCheese;
			if (cheese == 0) break;
		}
		System.out.println(time);
		System.out.println(cheese + meltedCheese);
    }
    
    static int melting(int r, int c) {
    	Queue<int[]> q = new ArrayDeque<>();
    	boolean[][] visited = new boolean[N][M];
    	int cnt = 0;
    	q.add(new int[] {r, c});
    	visited[r][c] = true;
    	while (!q.isEmpty()) {
    		int[] now = q.poll();
    		for (int i = 0; i < 4; i++) {
    			int nr = now[0] + dr[i];
    			int nc = now[1] + dc[i];
    			
    			if (nr < 0 || nc < 0 || N <= nr || M <= nc || visited[nr][nc]) continue;
    			
    			visited[nr][nc] = true;
    			if (map[nr][nc] == 0) q.add(new int[] {nr, nc});
        		else {
        			map[nr][nc] = 0;
        			cnt++;
        		}
    			
    		}
    		
    	}
    	return cnt;
    }

}
