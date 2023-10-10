import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;


public class Main {
	
	static char[] combArr;
	static int[] combNum;
	static char[][] arr;
	static boolean[][] visited;
	static Queue<int[]>q;
	static int result;
	static int answer;
	
	static int[] dx= {1,-1,0,0};
	static int[] dy= {0,0,1,-1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		arr=new char[5][5];
		combArr=new char[7];
		combNum=new int[7];
		q=new ArrayDeque<>();
		
		// 입력
		for(int i=0; i<5; i++) {
			String str=br.readLine();
			for(int j=0; j<5; j++) {
				arr[i][j]=str.charAt(j);
			}
		}
		
		// 7개뽑는 조합
		comb(0,0);
		System.out.println(answer);
	}

	private static void comb(int cnt, int start) {
		// 뽑기 완료
		if(cnt==7) {
			int sCnt=0;
			// System.out.println(Arrays.toString(combArr));
			// System.out.println(Arrays.toString(combNum));
			// S가 4개 이상이면 새 arr만들어주고 bfs로 연결 확인
			for(int i=0; i<7; i++) {
				if(combArr[i]=='S') sCnt++; 
			}
			if(sCnt>=4) {
				result=0;
				int[][] newArr=new int[5][5];
				visited=new boolean[5][5];
				
				for(int i=0; i<7; i++) {
					int x=combNum[i]/5;
					int y=combNum[i]%5;
					newArr[x][y]=1;
				}
				
				// 방문하지 않았고 1이면 bfs, cnt++
				for(int i=0; i<5; i++) {
					for(int j=0; j<5; j++) {
						if(newArr[i][j]==1 && !visited[i][j]) {
							result++;
							visited[i][j]=true;
							q.add(new int[] {i,j});
							bfs(newArr);
						}
					}
				}
				
				if(result==1) answer++;
			}
			
		}
		else {
			for(int i=start; i<25; i++) {
				int x=i/5;
				int y=i%5;
				combArr[cnt]=arr[x][y];
				combNum[cnt]=i;
				comb(cnt+1, i+1);
			}
		}
		
	}

	private static void bfs(int[][] newArr) {
		while(!q.isEmpty()) {
			int[] qArr=q.poll();
			int x=qArr[0];
			int y=qArr[1];
			
			for(int i=0; i<4; i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				
				if(isRange(nx,ny) && newArr[nx][ny]==1 && !visited[nx][ny]) {
					q.add(new int[] {nx,ny});
					visited[nx][ny]=true;
				}
			}
			
		}
		
	}

	private static boolean isRange(int nx, int ny) {
		if(nx>=0 && nx<5 && ny>=0 && ny<5) return true;
		return false;
	}

}