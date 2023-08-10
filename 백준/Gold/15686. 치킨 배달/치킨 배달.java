import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Vec2{
	public int x,y;
	public Vec2(int x,int y) {
		this.x = x;
		this.y = y;
	}
	public int GetDistTo(Vec2 other) {
		return Math.abs(this.x - other.x) + Math.abs( this.y - other.y);
	}
}


public class Main {
	static int N,M;
	static int map[][];
	
	static Vec2 Homes[];
	static Vec2 Stores[];

	static int homenum = 0;
	static int storenum = 0;
	
	static int selectedStores[];
	static boolean visited[];
	static int g_city_chiken_length = Integer.MAX_VALUE;
	
	static void dfs(int curr) {
		if (curr == M){
			int city_chiken_length = 0;
			for(int i =0; i< homenum;i++) {
				int chikenlength = Integer.MAX_VALUE;
				for(int j = 0; j < M; j++) {
					chikenlength = Math.min(chikenlength, Homes[i].GetDistTo(Stores[selectedStores[j]]));
				}
				city_chiken_length = city_chiken_length + chikenlength;
			}
			g_city_chiken_length = Math.min(g_city_chiken_length, city_chiken_length);
			return;
		}
		
		for(int i = 0; i < Stores.length;i++) {
			selectedStores[curr] = i;
			if (visited[i])
				return;
			visited[i]= true;
			dfs(curr + 1);
			visited[i]= false;
		}
	}
	
	
	
	public static void main(String args[])throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer  st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int [N][N];
		selectedStores = new int[M+1];
		
		for(int y = 0; y < N;y++) {
			st = new StringTokenizer(br.readLine());
			for(int x = 0; x < N;x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				if (map[y][x] == 1)
					homenum++;
				else if (map[y][x] == 2)
					storenum++;
			}
		}
		Homes = new Vec2[homenum];
		Stores = new Vec2[storenum];
		visited = new boolean[storenum];
		
		int homesize2= 0;
		int storesize2= 0;
		

		for(int y = 0; y < N;y++) {
			for(int x = 0; x < N;x++) {
				if (map[y][x] == 1)
					Homes[homesize2++] = new Vec2(x,y);
				else if (map[y][x] == 2)
					Stores[storesize2++] = new Vec2(x,y);
			}
		}
					
		dfs(0);
		System.out.println(g_city_chiken_length);
	}
}