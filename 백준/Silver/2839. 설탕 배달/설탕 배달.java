import java.util.Scanner;

public class Main {
	
	static int d[] = new int [5001];

	static int dp(int x) {
		if (x < 0) return 99998;
		if (x == 3 || x == 5) return 1;
		

		if (d[x] != 0) return d[x];
		return d[x] = Math.min(dp(x - 3) + 1, dp(x - 5) + 1);
	}
	
	public static void main(String args[]) {
		Scanner sc= new Scanner(System.in);
		
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			dp(i);
		}
		int res = dp(N);
		
		if (res < 5000)
			System.out.println(dp(N));
		else
			System.out.println(-1);
	}
}