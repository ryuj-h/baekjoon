import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int N,M;
	static int arr[];
	static boolean visited[];
	static int Max;
	
	static void dfs(int curr, int max) {
		if (curr == 2){
			if (max <= M){
				Max = Math.max(max, Max);
			}
			return;
		}
		
		for(int i = 0; i < N;i++) {
			if (visited[i])
				return;
			visited[i]= true;
			dfs(curr + 1,max + arr[i]);
			visited[i]= false;
		}
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			Max = Integer.MIN_VALUE;
		
			arr = new int [N];
			visited = new boolean[N];

			st = new StringTokenizer(br.readLine());
			
			for(int i =0; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			
			dfs(0,0);
			
			if (Max == Integer.MIN_VALUE) {
				Max = -1;
			}
			System.out.println("#" + tc +" "+ Max );
		}
	}
}