import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, population[];
	static boolean Subsetvisited[];
	static boolean visited[];// 
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	static int Solution = Integer.MAX_VALUE;
	
	public static void dfs(int curr, boolean flag) {//연결된 노드에 방문 후 visited 배열에 방문 체크
		for(int toNode : graph.get(curr)) {
			if (Subsetvisited[toNode] != flag)
				continue;
			if (visited[toNode])
				continue;
			visited[toNode] = true;
			dfs(toNode, flag);
		}
	}

	
	public static boolean isConnected() {
		Arrays.fill(visited, false);
		for(int i = 1; i <= N; i++) {//1번 구역 방문
			if(Subsetvisited[i] == true) {
				visited[i] = true;
				dfs(i, true);
				break;
			}
		}
		for(int i = 1; i <= N; i++) {//2번 구역 방문
			if(Subsetvisited[i] == false) {
				visited[i] = true;
				dfs(i, false);
				break;
			}
		}
		
		for(int i = 1; i<=N;i++) {
			if (visited[i] == false)//하나라도 방문하지 못한 곳이 있다면 
				return false;//실패!
		}
		return true;//모든 검사 통과, 성공.
	}
	
	public static void GenerateSubset(int curr,int tNum) {//부분집합을 구하고
		if (curr == N+1) {
			if (tNum != 0) {
				if (isConnected()) { //여기서 두 구역의 인구수 차이를 구한다.
					int team1num =0; int team2num = 0;
					
					for(int i =1 ;i <=N; i++) {
						if (Subsetvisited[i]) {
							team1num += population[i];
						}
						else
							team2num += population[i];
					}

					int abs = Math.abs(team2num - team1num);
					
					Solution = Math.min(Solution, abs);
				}
			}
			return;
		}
		Subsetvisited[curr] = true;
		GenerateSubset(curr + 1,tNum + 1);
		Subsetvisited[curr] = false;
		GenerateSubset(curr + 1, tNum);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		population = new int[N + 1];
		Subsetvisited = new boolean[N+1];
		visited = new boolean[N+1];
		
		StringTokenizer  st = new StringTokenizer(br.readLine());
		for(int i= 1; i<= N; i++) {
			population[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 0; i <= N; i++) {
			graph.add(new ArrayList<>());
	    }
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
            int gnum = Integer.parseInt(st.nextToken());
            
            for(int j = 0; j <gnum;j++ ) {
            	int toNode = Integer.parseInt(st.nextToken());
            	graph.get(i).add(toNode);
            }
        }
		GenerateSubset(0,0);
		if (Solution == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(Solution);
	}
}