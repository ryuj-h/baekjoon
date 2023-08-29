import java.util.Arrays;
import java.util.Scanner;

/**
 * 
 * DP 배열에 저장 해가며
 *  1. 3으로 나누고 DP배열에 있는지 확인
 *  2. 2로 나누고 DP배열에 있는지 확인
 *  3. 1을 빼고 DP배열에 있는지 확인
 *  
 * @author SSAFY
 *
 */
public class Main {
	static int DP[],N;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		DP = new int[N + 3];
		Arrays.fill(DP, Integer.MAX_VALUE);
		DP[1] = 0;
		DP[2] = 1;
		DP[3] = 1;
		
		for(int i = 4; i <= N; i++) {
			if (i % 3 == 0) {
				DP[i] = DP[i/3] + 1;
			}
			if (i % 2 == 0) {
				DP[i] = Math.min(DP[i],DP[i/2]+1);
			}
			DP[i] = Math.min(DP[i],DP[i-1] + 1);
		}
		
		System.out.println(DP[N]);
	}
}