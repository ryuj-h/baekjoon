import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int map[][];
	
	public static void main(String args[])throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		//StringTokenizer  st = new StringTokenizer(br.readLine());
		map = new int [N][N];
		
		
		for(int y= 0; y < N; y++) {
			char []  arr = br.readLine().toCharArray();	
			for(int x = 0;  x < N ; x++) {
				if (arr[x] == '1')
					map[y][x] = 1;
				else 
					map[y][x] = 0;
			}
		}
		
		makeSpace(0,0,N);
		
	}
	
	
	private static void makeSpace(int sr,int sc, int size) {
		int sum =0;
		
		for(int y = sr; y < sr + size; y++) {
			for(int x = sc; x < sc + size; x++) {
				sum += map[y][x];
			}
		}
		
		if (sum == 0) {//white
			System.out.print("0");
		}else if (sum == size * size) {
			System.out.print("1");
		}else{
			int half = size / 2;

			System.out.print("(");
			makeSpace(sr,sc,half);
			makeSpace(sr,sc + half,half);
			makeSpace(sr+ half,sc,half);
			makeSpace(sr+ half,sc+ half,half);
			System.out.print(")");
		}
	}
}