import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 
 * 집 N개, 1번부터 N번까지 집
 * 빨, 초, 파 중 하나의 색으로 칠함, 규칙
 * 
 * 1번집은 2번집과 색이 같지 않음
 * N번집은 N-1번 집의 색과 같지 않음
 * 그 사이 전부 동일
 * 
 * 풀이방식
 * DP 배열을 2차원배열로 만들어
 * 마지막에 빨간색을 쓰고 그 전까지 최소 비용을 갖는 DP배열을 DP[][0]에 저장
 * 나머지도 동일하게
 * 마지막에 3배열의 마지막 값을 비교하여 최솟값 반환
 * 
 * @author SSAFY
 *
 */
public class Main {

	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int REDS[] = new int[N+1];
		int GREENS[]= new int[N+1];
		int BLUES[]= new int[N+1];
		
		int DP[][] = new int[N+1][3];
		//DP[][0] -> 마지막으로 빨간색 사용
		//DP[][1] -> 마지막으로 초록색 사용
		//DP[][2] -> 마지막으로 파랑색 사용

		for(int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			REDS[i] = Integer.parseInt(st.nextToken());
			GREENS[i] = Integer.parseInt(st.nextToken());
			BLUES[i] = Integer.parseInt(st.nextToken());
		}
		for(int i = 1; i <=N;i++) {
			DP[i][0] = Math.min(DP[i-1][1],DP[i-1][2]) + REDS[i];
			DP[i][1] = Math.min(DP[i-1][0],DP[i-1][2]) + GREENS[i];
			DP[i][2] = Math.min(DP[i-1][1],DP[i-1][0]) + BLUES[i];
		}
		System.out.println(Math.min(DP[N][0],Math.min(DP[N][1], DP[N][2])));
	}
}