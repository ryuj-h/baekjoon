import java.util.Scanner;

/**
 * 
 * 
 * 점화식
 * Dp[n] = Dp[n-1] + Dp[n-2]
 * 
 * @author SSAFY
 *
 */

public class Main {
	static long DP[];
	static int N;
	
	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		DP = new long[N + 3];
		DP[0] = 1;
		DP[1] = 1;
		DP[2] = 2;
		for(int i = 3; i <= N;i++) {
			DP[i] = (DP[i-1] + DP[i-2]) % 10007;
		}
		System.out.println(DP[N]);
	}
}