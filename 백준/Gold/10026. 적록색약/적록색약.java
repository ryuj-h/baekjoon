import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static char map[][];
	static char map2[][];
	static int dx[] = {0,0,-1,1};
	static int dy[] = {-1,1,0,0};
	
	
	/**
	 * 
	 * @param flag 적록색약의 유무
	 */
	public static void bfs(char [][] map, boolean flag, int x,int y) {
		Queue<int[]> q = new LinkedList<>();
		
		q.offer(new int[] {x,y});
		char color = map[y][x];
		map[y][x] = '0';
		
		while(!q.isEmpty()) {
			int currinfo[] = q.poll();
			int currx = currinfo[0];
			int curry = currinfo[1];
			
			for(int d = 0; d < 4; d++) {
				int nextx = currx + dx[d];
				int nexty = curry + dy[d];
				
				if (nextx < 0 || nextx >= N || nexty <0 || nexty >= N)
					continue;
				
				if (flag == false) {
					if (map[nexty][nextx] != color)
						continue;	
				}
				else {
					if ((color == 'R' || color == 'G') && (map[nexty][nextx] == 'R' || map[nexty][nextx] == 'G')) {
						//적록 구분 못해요!
						
					}
					else {
						if (map[nexty][nextx] != color)
							continue;	
					}
				}

				map[nexty][nextx] = '0';
				q.offer(new int [] {nextx,nexty});
			}
		}
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new char[N][N];
		map2 =new char[N][N];
		 
		for(int y = 0; y< N; y++) {
			map[y] = br.readLine().toCharArray();
			map2[y] = map[y].clone();
		}

		int Solution1 = 0;
		int Solution2 = 0;
		for(int y= 0; y< N; y++) {
			for(int x= 0; x< N; x++) {
				if (map[y][x] != '0') {
					bfs(map,false,x,y);
					Solution1 ++;
				}
				if (map2[y][x] != '0') {
					bfs(map2,true,x,y);					
					Solution2++;
				}
			}
		}
		
		System.out.println(Solution1 + " "+ Solution2);
	}
}