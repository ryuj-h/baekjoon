import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
	static int N;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1,Integer o2) {
				if( Math.abs(o1) < Math.abs(o2))
					return -1;
				else if (Math.abs(o1) == Math.abs(o2)) {
					if (o1 < o2)
						return -1;
					else
						return 1;
				}else
					return 1;
			}
		});

		for(int i = 0 ; i < N ; i++) {
			int number = Integer.parseInt(br.readLine());
			if (number == 0) {
				if (!priorityQueue.isEmpty())
					System.out.println(priorityQueue.poll());
				else
					System.out.println(0);
			}else {
				priorityQueue.add(number);	
			}
		}
	}
}