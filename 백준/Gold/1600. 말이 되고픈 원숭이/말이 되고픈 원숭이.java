import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/**
 * 풀이전략: dx dy배열 8개를 선언해서 bfs로 완전 탐색.
 * 		방문 배열을 int [][][] 3차원으로 만들어서 마지막 부분에는 K값을 넣어줌
 * 
 * @author SSAFY
 *
 */
public class Main {
	static int K, W,H,Map[][];
	
	static int VisitedInt[][];
	
	static int Visited_int[][];
	static boolean Visited[][][];
	static int dx[] = {1,0,0,-1};
	static int dy[] = {0,1,-1,0};
	static int horseDx[] = {1,2,-1,-2,1,2,-2,-1};
	static int horseDy[] = {2,1,-2,-1,-2,-1,1,2};
	
	
	public static class Point{
		public int x,y,items, numOfWalk;
		public Point(int x, int y, int items,int numOfWalk) {
			super();
			this.x = x;
			this.y = y;
			this.items = items;
			this.numOfWalk = numOfWalk;
		}
	}
	
	public static int bfs() {
		Deque<Point> que = new ArrayDeque<>();
		que.add(new Point(0,0,K,0));
		Visited[0][0][K] = true;
		if (0 == W - 1 && 0 ==  H -1) 
			return 0;
		
		while(!que.isEmpty()) {
			Point curr = que.poll();
			//System.out.println(curr.x + " , " + curr.y + " , " +curr.items);
			
			for(int d = 0; d < 4; d++) {
				int nextx = curr.x + dx[d];
				int nexty = curr.y + dy[d];
				
				if(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H)
					continue;
				if (Map[nexty][nextx] == 1)
					continue;
				if (Visited[nexty][nextx][curr.items])
					continue;
				
				if (nextx == W - 1 && nexty ==  H -1) 
					return curr.numOfWalk + 1;
				Visited[nexty][nextx][curr.items] = true;
				que.add(new Point(nextx,nexty,curr.items,curr.numOfWalk + 1));
			}


			if (curr.items > 0) {
				for(int d= 0; d< 8;d++) {
					int nextx = curr.x + horseDx[d];
					int nexty = curr.y + horseDy[d];
					if(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H)
						continue;
					if (Map[nexty][nextx] == 1)
						continue;
					if (Visited[nexty][nextx][curr.items - 1])
						continue;
					
					if (nextx == W - 1 && nexty ==  H -1) 
						return curr.numOfWalk + 1;
					Visited[nexty][nextx][curr.items -1] = true;
					que.add(new Point(nextx,nexty,curr.items -1,curr.numOfWalk + 1));
				}
			}
			

		}
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		Map = new int[H][W];
		Visited = new boolean[H][W][31];
		for(int y = 0;y<H;y++) {
			st = new StringTokenizer(br.readLine());
			for(int x = 0;x < W;x++) {
				Map[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.println(bfs());
	}
}