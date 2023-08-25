import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/**
 * 
 * 풀이 조건
 * 최대한 많은 Core에 전원을 연결하였을 경우, 전선 길이의 합을 구하고자 한다.
 * 단, 여러 방법이 있을 경우, 전선 길이의 합이 최소가 되는 값을 구하라.
 * 
 * 풀이 방식
 * Core 라는 노드를 만들어서, 이 노드가 연결 된경우 , 안 된 경우를 나누어서 방향을 나누면서 
 * dfs탐색을 돌린다.
 * @author SSAFY
 *
 */

public class Solution {

	static class Core{
		int x,y;
	}
	
	static int T;
	static int N;
	static int Map[][];
	static int corenum;
	static int dx[] = {-1,1,0,0};//좌 상 우 하
	static int dy[] = {0,0,-1,1};
	static int Solution;
	static int SolutionDist;
	static Core core[];
	
	
	/**
	 * 현재 방향 대로 코어와 전선을 연결하며 재귀 호출로 총 연결된 길이를 return
	 * 
	 * @param dir
	 * @param currx
	 * @param curry
	 * @return 연결된 길이
	 */
	public static int Connect(int dir, int currx,int curry) {
		if (currx < 0 || currx >= N || curry < 0 || curry >= N)
			return 1;
		if (Map[curry][currx] == 1 || Map[curry][currx] == -1)
			return 0;
		int nb = Connect(dir, currx + dx[dir], curry + dy[dir]);
		if (nb > 0){
			Map[curry][currx] = -1;
			return nb + 1;
		}
		else
			return 0;
	}
	
	
	/**
	 * 
	 * 전선이 지나갔던 자리를 원상복구
	 * @param dir
	 * @param currx
	 * @param curry
	 */
	public static void DisConnect(int dir, int currx, int curry) {
		if (currx < 0 || currx >= N || curry < 0 || curry >= N)
			return;
		Map[curry][currx] = 0;
		DisConnect(dir, currx + dx[dir], curry + dy[dir]);
	}

	
	/**
	 * dfs
	 * 
	 * @param index 현재 인덱스
	 * @param connectednum 연결된 코어의 수
	 * @param connectedline 총 연결된 전선의 길이
	 */
	public static void dfs(int index, int connectednum, int connectedline) {
		
		//우선순위에 맞춰서 연결된 길이를 설정해줌
		if (Solution < connectednum) {
			Solution = connectednum;	
			SolutionDist = connectedline;
		}
		else if ( Solution == connectednum) {
			SolutionDist = Math.min(SolutionDist, connectedline);
		}
		
		if (index == corenum) {
			return;
		}
		
		//4방 돌면서 연결해보고 dfs 시도
		for(int d = 0; d < 4; d++) {
			int conect = Connect(d,core[index].x + dx[d],core[index].y + dy[d]);
			if ( conect > 0) {
				dfs(index + 1,connectednum+1 ,connectedline+conect -1);
				DisConnect(d,core[index].x+ dx[d],core[index].y+ dy[d]);	
			}	
		}
		//또한 아무것도 연결하지 않고도 dfs 시도
		dfs(index+1, connectednum,connectedline );
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		
		for(int tc = 1; tc <= T;tc++) {
			N = Integer.parseInt(br.readLine());
			Map = new int[N][N];
			Solution = Integer.MIN_VALUE;
			SolutionDist = Integer.MAX_VALUE;
			corenum = 0;
			
			core = new Core[12];
			for(int y= 0;y<N;y++) {
				st = new StringTokenizer (br.readLine());
				for(int x= 0; x< N;x++) {
					Map[y][x] = Integer.parseInt(st.nextToken());
					
					if (Map[y][x] == 1) {
						core[corenum] = new Core();
						core[corenum].x = x;
						core[corenum].y = y;
						corenum++;
					}
				}
			}
			dfs(0,0,0);
			System.out.println("#" + tc + " " + SolutionDist);
		}
	}
}