import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * 
 * 서쪽 N개 동쪽 M개 사이트 ( N<=M )
 * 서쪽  동쪽 연결 한 사이트 당 다리 하나
 * 
 * 조합 문제, 수업시간 코드 활용
 * 
 * @author SSAFY
 */

public class Main {
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc =0 ;tc < T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int K = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int [][] B = new int[N+1][K+1];
			
			for(int i =0; i <= N;i++) {
				for(int j = 0,end = Math.min(i, K); j<= end ; j++) {
					if (j == 0 || i == j) B[i][j] = 1;
					else B[i][j] = B[i-1][j-1] + B[i-1][j];
				}
			}
			System.out.println(B[N][K]);		
		}
	}
}