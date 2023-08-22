import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class CCTV{
	public int x,y,type,dir;
}

public class Main {
	static int N, M;
	static int map[][];
	static int savemap[][];
	static CCTV cctvs[] = new CCTV[8];
	static int cctvnum = 0;
	static int dx[] = {-1,0,1,0};
	static int dy[] = {0,-1,0,1};
	static int Solution = Integer.MAX_VALUE;
	
	public static void EraseMarkedPart(CCTV cctv) {
		ArrayList <Integer> dirs = new ArrayList<>();
		
		switch(cctv.type) {
		case 1:
			dirs.add(cctv.dir);
			break;
		case 2:
			dirs.add(cctv.dir);
			dirs.add((cctv.dir+ 2) % 4);
			break;
		case 3:
			dirs.add(cctv.dir);
			dirs.add((cctv.dir + 1) % 4);
			break;
		case 4:
			dirs.add(cctv.dir);
			dirs.add((cctv.dir + 1) % 4);
			dirs.add((cctv.dir + 2) % 4);
			break;
		case 5:
			dirs.add(cctv.dir);
			dirs.add((cctv.dir + 1) % 4);
			dirs.add((cctv.dir + 2) % 4);
			dirs.add((cctv.dir + 3) % 4);
			break;
		}
		for (int dir : dirs) {
			int currx = cctv.x;
			int curry = cctv.y;
			
			while(true) {
				int nextx = currx + dx[dir];
				int nexty = curry + dy[dir];
				
				if (nextx <0 || nextx >= M || nexty <0 || nexty >= N)
					break;
				if (map[nexty][nextx] == 6)
					break;
				
				if (map[nexty][nextx] < 1)
					map[nexty][nextx] = 9;
				currx = nextx;
				curry = nexty;
			}
			
		}
	}
	
	public static void dfs(int index) {
		if(index == cctvnum) {
			for(int y= 0; y< N;y++) {
				for(int x = 0; x< M; x++) {
					savemap[y][x] = map[y][x];
				}
			}
			
			for(int i =0 ; i < cctvnum;i++) 
				EraseMarkedPart(cctvs[i]);
			

			int unmarkednum = 0;
			for(int y= 0;  y< N; y++) {
				for(int x = 0; x < M ;x++) {
					if (map[y][x] == 0) {
						unmarkednum++;
					}
				}
			}
			Solution = Math.min(unmarkednum, Solution);
			
			for(int y= 0; y< N;y++) {
				for(int x = 0; x< M; x++) {
					map[y][x] =savemap[y][x];
				}
			}
			return;
		}
		
		for(int d =0; d<4;d++) {
			cctvs[index].dir = d;
			dfs(index+1);
		}
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer (br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		savemap = new int[N][M];
		
		for(int y= 0;  y< N; y++) {
			st = new StringTokenizer (br.readLine());
			for(int x = 0; x < M ;x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				if (map[y][x] != 0 &&map[y][x] != 6 ) {
					cctvs[cctvnum] = new CCTV();
					cctvs[cctvnum].x = x;
					cctvs[cctvnum].y = y;
					cctvs[cctvnum].type = map[y][x];
					
					cctvnum++;
				}
			}
		}
		
		
		
		dfs(0);
		System.out.println(Solution);
	}
}