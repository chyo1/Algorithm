import java.util.*;
import java.io.*;

public class Main {
	static int N, M;
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] inputs = bf.readLine().split(" ");
		N = Integer.parseInt(inputs[0]);
		M = Integer.parseInt(inputs[1]);
		
		int[] nums = new int[N + 1];
		
		for (int i = 1; i <= N; i++)
			nums[i] = i;
		for (int i = 0; i < M; i++) {
			inputs = bf.readLine().split(" ");
			int s = Integer.parseInt(inputs[0]);
			int e = Integer.parseInt(inputs[1]);
			
			while (s < e) {
				int tmp = nums[e];
				nums[e] = nums[s];
				nums[s] = tmp;
				s++; e--;
			}
		}
		
		for (int i = 1; i <= N; i++)
			System.out.print(nums[i] + " ");
	}

}
