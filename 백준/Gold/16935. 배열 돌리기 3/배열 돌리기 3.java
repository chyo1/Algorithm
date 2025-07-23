import java.util.*;
import java.io.*;

class Main
{
	static int R, order;
	static final int UD = 1;
	static final int LR = 2;
	static final int R90 = 3;
	static final int L90 = 4;
	static final int CLOCK = 5;
	static final int BACK_CLOCK = 6;
	
    public static void main(String args[]) throws Exception
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = bf.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int M = Integer.parseInt(inputs[1]);
        R = Integer.parseInt(inputs[2]);
         
        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++) {
        	inputs = bf.readLine().split(" ");
        	for (int j = 0; j < M; j++) {
        		map[i][j] = Integer.parseInt(inputs[j]);
        	}
        }
        
        inputs = bf.readLine().split(" ");
        int[][] tmp = map;
        for (String input : inputs) {
	        order = Integer.parseInt(input);
	        switch(order) {
	        	case UD:
	        		tmp = changeUpDown(tmp);
	        		break;
	        	case LR:
	        		tmp = changeLeftRight(tmp);
	        		break;
	        	case R90:
	        		tmp = changeRight90(tmp);
	        		break;
	        	case L90:
	        		tmp = changeLeft90(tmp);
	        		break;
	        	case CLOCK:
	        		tmp = changeClock(tmp);
	        		break;
	        	case BACK_CLOCK:
	        		tmp = changeBackClock(tmp);
	        		break;
	
	        }
        }
        for (int i = 0; i < tmp.length; i++) {
            for (int j = 0; j < tmp[0].length; j++) {
                System.out.print(tmp[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    private static int[][] changeUpDown(int[][] map) {
    	int N = map.length;
    	int M = map[0].length;
    	int[][] tmp = new int[N][M];
    	int r = 0;
    	int c = 0;
    	for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                tmp[r][c++] = map[i][j];
            }
            r++;
            c = 0;
        }
    	return tmp;
    }
    
    private static int[][] changeLeftRight(int[][] map) {
    	int N = map.length;
    	int M = map[0].length;
    	int[][] tmp = new int[N][M];
    	int r = 0;
    	int c = 0;
    	for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
            	tmp[r][c++] = map[i][j];
            }
            r++;
            c = 0;
        }
    	return tmp;
    }
    
    private static int[][] changeRight90(int[][] map) {
    	int N = map.length;
    	int M = map[0].length;
    	int[][] tmp = new int[M][N];
    	int r = 0;
    	int c = 0;
    	for (int j = 0; j < M; j++) {
            for (int i = N - 1; i >= 0; i--) {
            	tmp[r][c++] = map[i][j];
            }
            r++;
            c = 0;
        }
    	return tmp;
    }
    
    private static int[][] changeLeft90(int[][] map) {
    	int N = map.length;
    	int M = map[0].length;
    	int[][] tmp = new int[M][N];
    	int r = 0;
    	int c = 0;
        for (int j = M - 1; j >= 0; j--) {
            for (int i = 0; i < N; i++) {
            	tmp[r][c++] = map[i][j];
            }
            r++;
            c = 0;
        }
    	return tmp;
    }
    
    private static int[][] changeClock(int[][] map) {
    	int N = map.length;
    	int M = map[0].length;
    	int[][] mvC = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    	
    	int[][] tmp = new int[N][M];
    	for (int i = 0; i < 2; i++) {
    		for (int j = 0; j < 2; j++) {
    			
    			for (int r = i * N / 2; r < (i + 1) * N / 2; r++) {
    				for (int c = j * M / 2; c < (j + 1) * M / 2; c++) {
    					tmp[r][c] = map[r + mvC[i * 2 + j][0] * N / 2][c + mvC[i * 2 + j][1] * M / 2];
    				}
    			}
    			
    		}
    	}
    	
    	return tmp;
    }
    
    private static int[][] changeBackClock(int[][] map) {
    	int N = map.length;
    	int M = map[0].length;
    	int[][] mvBC = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    	int[][] tmp = new int[N][M];
    	for (int i = 0; i < 2; i++) {
    		for (int j = 0; j < 2; j++) {
    			
    			for (int r = i * N / 2; r < (i + 1) * N / 2; r++) {
    				for (int c = j * M / 2; c < (j + 1) * M / 2; c++) {
    					tmp[r][c] = map[r + mvBC[i * 2 + j][0] * N / 2][c + mvBC[i * 2 + j][1] * M / 2];
    				}
    			}
    			
    		}
    	}
    	
    	return tmp;
    }
    
}