import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/**
 * 
 * 
 * 
 * 풀이 1
 * 단순 DFS 탐색으로 갈 수 있는 모든 구역 탐색, 최솟값 반환
 * 
 * 풀이 2
 * DP 못풀겠다 
 * 
 * @author SSAFY
 */


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] map = new int[N + 1][N + 1];
        int[][][] dp = new int[N + 1][N + 1][3]; // dp[x][y][dir]: (x, y) 위치에서 dir 방향으로 파이프를 놓는 경우의 수

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[1][2][0] = 1; // 초기 위치 설정
        for (int x = 1; x <= N; x++) {
            for (int y = 3; y <= N; y++) {
                if (map[x][y] == 0) {
                    dp[x][y][0] = dp[x][y - 1][0] + dp[x][y - 1][2];
                    dp[x][y][1] = dp[x - 1][y][1] + dp[x - 1][y][2];
                    if (map[x - 1][y] == 0 && map[x][y - 1] == 0) {
                        dp[x][y][2] = dp[x - 1][y - 1][0] + dp[x - 1][y - 1][1] + dp[x - 1][y - 1][2];
                    }
                }
            }
        }

        int answer = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
        System.out.println(answer);
    }
}