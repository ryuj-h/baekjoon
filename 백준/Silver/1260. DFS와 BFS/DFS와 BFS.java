import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N,M,V, graph[][];
	static boolean visited[];
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer (br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken()) - 1;
		
		graph = new int[N][N];
		visited = new boolean[N];
		
		for(int i =0 ; i < M;i++) {
			st = new StringTokenizer (br.readLine());
			int num1 = Integer.parseInt(st.nextToken())-1;
			int num2 = Integer.parseInt(st.nextToken())-1;
			
			graph[num1][num2] = 1;
			graph[num2][num1] = 1;			
		}

		
		visited[V] = true;
		dfs(V);
		
		System.out.println();
		
		visited = new boolean[N];
		visited[V] = true;
		bfs(V);
	}
	
	public static void dfs(int curr) {
		System.out.printf("%d ",curr+1);
		for(int i =0 ; i < N;i++) {
			if (graph[curr][i] != 1) continue;
			if (visited[i]) continue;
			visited[i] = true;
			dfs(i);
		}
	}
	public static void bfs(int startnode) {
		Queue<Integer> queue = new LinkedList();
		
		queue.offer(startnode);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			System.out.printf("%d ",curr+1);
			
			
			for(int i =0 ; i < N;i++) {
				if (graph[curr][i] != 1) continue;
				if (visited[i]) continue;
				visited[i] = true;
				
				queue.offer(i);
			}
		}
	}
}