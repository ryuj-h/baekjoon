import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static int N;
	public static int map[][] = new int[101][101];
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		
		StringTokenizer st;// = new StringTokenizer();//br.readLine());
		for(int i = 1 ; i <=N;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			for(int yy = y+1;yy <= y + 10; yy++ ) {
				for(int xx = x+1 ;xx <= x + 10; xx++) {
					map[yy][xx] = i;
				}
			}
		}
		
		int nonarea = 0;
		for(int yy = 1; yy <= 100; yy++) {
			for(int xx = 1; xx <= 100; xx++) {
				if (map[yy][xx] == 0)
					nonarea++;
			}
		}
		System.out.println(10000 - nonarea);
		
	}
}