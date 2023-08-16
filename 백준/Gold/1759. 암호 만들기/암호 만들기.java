import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {//암호만들기 류진호
	
	static int L,C;
	static char keys[];
	static boolean visited[];
	static char solution[];
	
	private static boolean is모음(char c) {
		if (c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' )
			return true;
		return false;
	}
	
	private static void dfs(int depth, int currindex,int 자음, int 모음) {
		//System.out.println(keys);
		if (depth == L) {
			if (자음 >= 2 && 모음 >=1) {
				System.out.println(solution);
			}
			return;
		}
		for(int i =0; i < C; i++) {
			if (visited[i]) 
				continue;
			if ((int)keys[i] - (int)keys[currindex] < 0)
				continue;
			boolean amI모음 = is모음(keys[i]);

			int 자음2 = 0;
			int 모음2 = 0;
			if (amI모음) 
				모음2++;
			else
				자음2++;
				
			visited[i] = true;
			solution[depth] = keys[i];
			dfs(depth +1, i,자음+자음2,모음+모음2);
			visited[i] = false;
		}
	}
	
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer (br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		keys = new char[C];
		visited = new boolean[C];
		solution = new char[L];
		
		st = new StringTokenizer(br.readLine());
		for(int i= 0; i< C;i++) {
			keys[i] = st.nextToken().toCharArray()[0];
		}
		
		Arrays.sort(keys);
		
		for(int i =0; i < C; i++) {
			boolean is모음_ =is모음(keys[i]);
			int 모음 = 0;
			int 자음 = 0;
			if (is모음_) 
				모음++;
			else
				자음++;

			visited[i] = true;
			solution[0] = keys[i];
			dfs(1,i,자음,모음);
			visited[i] = false;
		}
	}
}