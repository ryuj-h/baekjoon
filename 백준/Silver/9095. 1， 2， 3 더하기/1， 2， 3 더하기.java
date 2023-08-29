import java.util.Scanner;

/**
 * 풀이방법
 * 암만 봐도 DP같으나 점화식 구하는 방법을 모르기에
 * dfs를 통해서 조금 구해놓고 규칙을 찾아보자
 * 
 * @author SSAFY
 * 
 * 1 2 4 7 13 24
 * 
 * 점화식
 * DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
 */


public class Main {
	static long DP[];
	static int T,N,Solution = 0;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		T = sc.nextInt();
		for(int i =0 ;i < T; i++) {
			N = sc.nextInt();

			DP = new long[N + 3];
			DP[0] = 0;
			DP[1] = 1;
			DP[2] = 2;
			DP[3] = 4;
			for(int i1 = 4; i1 <= N;i1++) {
				DP[i1] = DP[i1-1] + DP[i1-2]+ DP[i1-3];
			}
			System.out.println(DP[N]);	
		}
	}
}