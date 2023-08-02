import java.util.Scanner;

public class Main {
	static int N, M;
	static StringBuilder sb = new StringBuilder();
	static int picked[];
	static boolean visited[];
	
	public static void comb(int cnt, int start) {
		if(cnt == M) {
			for(int i =0; i < M;i++) {
				sb.append(picked[i] + " ");		
			}
			sb.append("\n");
		}
		for(int i = start; i < N; i++) {
			if (visited[i]) continue;
			
			visited[i] = true;
			picked[cnt] = i + 1;
			comb(cnt + 1, i + 1);
			visited[i] = false;
		}
	}
	
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		visited = new boolean [N];
		picked = new int[N];
		comb(0, 0);
		System.out.println(sb);
	}
}