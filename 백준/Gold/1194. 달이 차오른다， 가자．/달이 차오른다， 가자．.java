import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;


/**
 * 
 * 방문 처리를 어떻게 할까?
 * 2차원 boolean배열은 불가능
 * 3차원 boolean배열은 (N * M * 0x7f) 가능? 불가능. 열쇠를 먹고 돌아가는길에서 돌아 갈 수 없음
 * 4차원 boolean 배열은 (N * M * 0x7F * 0x7F) 가능?[y][x]...? 
 * 
 * 3차원 배열로 마지막 요소를 key값을 비트마스킹으로 만들어서 체크
 * 
 * @author SSAFY
 */

public class Main {
	static int N,M;
	static char Map[][];
	static boolean Visited[][][];//x,y,char 값
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	
	private static class Pos{
		int x;
		int y;
		int keyStatus;
		//key 111111
		//    abcdef
		//각 비트마다 키를 가지고 있으면 1, 없으면 0
		int move;
		//얼마나 움직였는지
		
		public Pos(int x, int y, int keyStatus, int move) {
			super();
			this.x = x;
			this.y = y;
			this.keyStatus = keyStatus;
			this.move = move;
		}
	}
	
	/**
	 * 
	 * 
	
	빈 칸: 언제나 이동할 수 있다. ('.')
	벽: 절대 이동할 수 없다. ('#')
	열쇠: 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. ('a', 'b', 'c', 'd', 'e', 'f')
	문: 대응하는 열쇠가 있을 때만 이동할 수 있다. ('A', 'B', 'C', 'D', 'E', 'F')
	민식이의 현재 위치: 빈 곳이고, 민식이가 현재 서 있는 곳이다. ('0')
	출구: 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. ('1')
	
	 * 
	 * @param startpos
	 * @return
	 */
	
	
	public static int bfs(Pos startpos) {
		Deque<Pos> deque = new ArrayDeque<>();
		deque.add(startpos);
		while(!deque.isEmpty()) {
			Pos currpos = deque.poll();
			for(int d= 0;d < 4;d++) {
				int nx = currpos.x + dx[d];
				int ny = currpos.y + dy[d];
				int keyStatus = currpos.keyStatus;
				
				if(nx<0 || nx >= M|| ny <0 || ny >= N)
					continue;
				if (Map[ny][nx] == '1')
					return currpos.move + 1;
				if (Map[ny][nx] == '#')
					continue;
				
				if(Visited[ny][nx][currpos.keyStatus])
					continue;

				if (Map[ny][nx] >= 'a' && Map[ny][nx] <= 'f')
					keyStatus |= (1 << (Map[ny][nx] - 'a'));
				if (Map[ny][nx] >= 'A' && Map[ny][nx] <= 'F') {
					if((currpos.keyStatus & (1 << Map[ny][nx]- 'A')) == 0) {
						continue;
					}
				}

				deque.add(new Pos(nx, ny, keyStatus, currpos.move+1));
				Visited[ny][nx][keyStatus] = true;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		Map = new char[N][M];
		Visited = new boolean[N][M][1<<6];
		Pos start = null;
		
		for(int y = 0; y <N;y++) {
			char[] line = br.readLine().toCharArray();
			for(int x= 0; x < M; x++) {
				Map[y][x] = line[x];

				if(Map[y][x] == '0') {
					start = new Pos(x, y, 0, 0);
				}
			}
		}
		System.out.println(bfs(start));
	}
}