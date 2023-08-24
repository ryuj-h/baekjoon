import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int info[][];
	static boolean visited[];
	static int made[];
	static int made2[];
	static int rouxs[];
	static int Solution = Integer.MIN_VALUE;
	static int rouxs2[];
	
	
	
	public static void BaseBall() {
		
		int fullScore = 0;
		int turn = 0;
		for(int i =0 ; i< N;i++) {
			int outcount = 0;
			
			for(int j = 0; j < 9;j++) {
				rouxs[j] = 0;
			}
			
			while(true) {
				int currhitter =made[turn % 9];
				int curr_hitter_score = info[i][currhitter];
				
				if (curr_hitter_score == 0) {
					rouxs[currhitter] = 0;
					outcount++;
				}
				if (outcount == 3) {
					outcount = 0;
					turn++;
					break;
				}
				
				for(int j = 0; j < 9; j++) {
					if (rouxs[made[j]] == 0 ||  made[j] == currhitter)
						continue;
					rouxs[made[j]] =rouxs[made[j]] + curr_hitter_score;
					if (rouxs[made[j]] >= 4) {
						fullScore++;
						rouxs[made[j]] = 0;
					}
				}
				
				rouxs[currhitter] += curr_hitter_score;
				if (rouxs[currhitter] >= 4) {
					fullScore++;
					rouxs[currhitter] = 0;
				}	
				
				turn++;
			}
			
		}
		Solution = Math.max(Solution, fullScore);
	}
	
	
	
	
	public static void dfs(int curr,int depth) {// 순서를 만들고
		if(depth == 9) {

			
			BaseBall();
			return;
		}
		if (depth == 3) {
			visited[0] = true;
			made[depth] = 0;
			dfs(0,depth+1);
			visited[0] = false;
		}
		else {
			for(int i =1; i< 9; i++) {
				if (visited[i])
					continue;
				
				visited[i] = true;
				made[depth] = i;
				dfs(i,depth + 1);
				visited[i] = false;
			}	
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		info = new int[N][9];
		made = new int[9];
		visited = new boolean[9];
		rouxs = new int[9];
		made2 = new int[9];
		rouxs2 = new int [5];
		
		StringTokenizer  st;
		for(int i =0; i < N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 9; j++) {
				info[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(1,0);
		
		System.out.println(Solution);
	}
}