import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N,M;
	static List<Integer>[] list;
	static int degree[];
	
	public static void bfs() {
		Queue <Integer> q = new ArrayDeque<>();
		for(int i =1 ; i<= N; i++) {
			if (degree[i] == 0)
				q.offer(i);
		}
		
		while(!q.isEmpty()) {
            int from = q.poll();
            System.out.printf("%d ", from);
            for(int to : list[from]) {
                if( --degree[to]==0 ) q.offer(to);
            }
		}
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer (br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		list = new List[N + 1];
		degree = new int[N + 1];
        for(int i=1; i<=N; i++) list[i] = new ArrayList<>();
		
		for(int i =0; i < M;i++) {
			st = new StringTokenizer (br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			list[from].add(to);
			degree[to]++;
		}
		bfs();
	}
}