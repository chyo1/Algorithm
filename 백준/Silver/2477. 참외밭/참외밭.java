import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("Test3.txt"));
		//---------여기에 코드를 작성하세요.---------------//
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int cal = Integer.parseInt(bf.readLine());
		
		int[] total = new int[2];
		List<int[]> l = new ArrayList<>();
		for (int i = 0; i < 6; i++) {
			String[] inputs = bf.readLine().split(" ");
			int dir = Integer.parseInt(inputs[0]);
			int len = Integer.parseInt(inputs[1]);
			
			total[(dir - 1) / 2] += len;
			l.add(new int[]{dir, len});
		}
		
		int sum = total[0] * total[1] / 4;
		int size = l.size();
		for (int i = 0; i < size; i++) {
			if (l.get(i % size)[0] == l.get((i + 2) % size)[0] && (l.get((i + 1) % size)[0] == l.get((i + 3) % size)[0])) {
				sum -= (l.get((i + 1) % size)[1] * l.get((i + 2) % size)[1]);
			}
		}
		System.out.println(sum * cal);
	}

}