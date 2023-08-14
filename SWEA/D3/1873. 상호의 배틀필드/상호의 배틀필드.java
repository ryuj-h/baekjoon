import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
	static int T;
	static int H, W;
	static int N;
	static char Orders[];
	static char Map[][];
	
	static int gx,gy;//내 포지션
	static int dx,dy;
	static char NextDirCharactor;
	
	public static void move() {
		int nextx = gx + dx;
		int nexty = gy + dy;
		if (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || Map[nexty][nextx] != '.') {
			Map[gy][gx] = NextDirCharactor;
			return;
		}
		
		Map[gy][gx] = '.';
		gx = nextx;
		gy = nexty;
		Map[gy][gx] = NextDirCharactor;
	}
	
	public static void shot(int mx, int my) {
		int nextx = mx + dx;
		int nexty = my + dy;
		if (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H) 
			return;
		if (Map[nexty][nextx] == '#')
			return;
		if (Map[nexty][nextx] == '*') {
			Map[nexty][nextx] = '.';
			return;
		}
		shot(nextx,nexty);
	}
	
	public static void turn(char order) {
		if (order == 'S') {
			shot(gx,gy);
			return;
		}else if (order == 'U') {
			dx = 0;dy = -1;
			NextDirCharactor = '^';
		}else if (order == 'D') {
			dx = 0;dy = 1;
			NextDirCharactor = 'v';
		}else if (order == 'R') {
			dx = 1;dy = 0;
			NextDirCharactor = '>';
		}else if (order == 'L') {
			dx = -1;dy = 0;
			NextDirCharactor = '<';
		}
		move();
	}
	public static void print () {
		for (int y = 0 ;y < H; y++) {
			System.out.println(Map[y]);
		}
	}
	
	public static void main(String args[]) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			StringTokenizer  st = new StringTokenizer(br.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
	
			Map = new char[H][W];
			
			for (int y = 0 ;y < H; y++) {
				char ca[] = br.readLine().toCharArray();
				for(int x= 0; x < W; x++) {
					Map[y][x] = ca[x];
					
					if (ca[x] == '<' ||ca[x] == '>' ||ca[x] == '^' ||ca[x] == 'v') {
						gx = x;
						gy = y;
						if (ca[x] == '<') {
							dx = -1;
							dy = 0;
						}else if ( ca[x] == '>') {
							dx = 1;
							dy = 0;
						}else if ( ca[x] == '^') {
							dx = 0;
							dy = -1;
						}else if ( ca[x] == 'v') {
							dx = 0;
							dy = 1;
						}
					}
				}
			}
			
			N = Integer.parseInt(br.readLine());
			Orders = br.readLine().toCharArray();
			
			Scanner sc = new Scanner(System.in);
			for(int i =0; i < N; i++) {
				turn(Orders[i]);
			}
			System.out.printf("#%d ",tc);
			print();				
		}
	}
}