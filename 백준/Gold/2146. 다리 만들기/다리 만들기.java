import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * 1. bfs를 이용해서 섬을 라벨링한다
2. 각 섬의 테두리의 좌표를 bfs의 시작점으로 설정한다.
3. 모든 테두리에서 bfs로 가장 가까운 섬의 좌표를 구한다. 0이면 큐에 넣어주고 같은 섬이면 패스하고 다른 섬이면 4번을 진행한다
4. x,y의 차이를 구한다
 * */

public class Main {
	
	static int N;
	static int[] dx= {1,0,-1,0}; // 하 우 상 좌
	static int[] dy= {0,1,0,-1};
	static int[][] arr;
	static boolean[][] visited;
	static int min;
	static Queue<int[]>q;
	
	 public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		arr=new int[N][N];
		visited=new boolean[N][N];
		min=Integer.MAX_VALUE;
		q=new ArrayDeque<int[]>();
		
		Queue<int[]>ocean=new ArrayDeque<>();
		boolean[][] bridgeVisited=new boolean[N][N];
		
		// 섬 입력받기
		for(int i=0; i<N; i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {	
				char ch=st.nextToken().charAt(0);
				arr[i][j]=ch-'0';
			}
		}
		
		int label=1;
		
		// 섬 라벨링
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(arr[i][j]==1 && !visited[i][j]) {
					visited[i][j]=true;
					q.add(new int[] {i,j});
					labelBfs(i, j, label);
					label++;
				}	
			}
		}
		
		// 테두리 체크
		for(int i=0; i<N; i++) {
			for (int j = 0; j < N; j++) {
				// 4방중 범위를 넘지 않고 현재 값이 0이 아니고 다음값이 0이면 테두리. bfs 진행. 탐색한 테두리 방문처리
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (isRange(nx, ny) && arr[nx][ny] == 0 && arr[i][j] != 0) {
						if (bridgeVisited[i][j]) continue;
						bridgeVisited[i][j] = true;
						bfs(i, j, ocean);
					}
				}
			}
		}
		
		
		System.out.println(min);
		
	}

	private static void bfs(int startX, int startY, Queue<int[]> ocean) {
		boolean[][] visited=new boolean[N][N];
		
		ocean.add(new int[] {startX,startY});
		visited[startX][startY]=true;
		
		// 모든 테두리에서 bfs로 가장 가까운 섬의 좌표를 구함.	
		while(!ocean.isEmpty()) {
			
			int[] oceanArr=ocean.poll();
			int x=oceanArr[0];
			int y=oceanArr[1];
			
			for (int i= 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

			// 다음 좌표가 0이면 큐에 넣어줌. 같은 칸을 확인할 수 있으므로 방문 처리. 라벨 확인해서 다른 섬인 경우에만 x,y 차이 구하기.
				if (isRange(nx, ny) && !visited[nx][ny]) {
					
					if (arr[nx][ny] != 0 && arr[nx][ny] != arr[startX][startY]) {
						int result = Math.abs(nx - startX) + Math.abs(ny - startY) - 1;
						min = Math.min(min, result);
                        visited[nx][ny]=true;
					}
					else if(arr[nx][ny] == 0) {
						ocean.add(new int[] { nx, ny });
						visited[nx][ny] = true;
					}
					
				}
				
			}
				
		}
		
		
	}

	private static void labelBfs(int i, int j, int label) {
		while(!q.isEmpty()) {
			int[] qArr=q.poll();
			int x=qArr[0];
			int y=qArr[1];
			arr[x][y]=label;
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				if(isRange(nx,ny) && arr[nx][ny]==1 && !visited[nx][ny]) {
					visited[nx][ny]=true;
					q.add(new int[] {nx, ny});
				}
			}
		}
	}

	private static boolean isRange(int nx, int ny) {
		if(nx>=0 && nx<N && ny>=0 && ny<N) return true;
		return false;
	}
}