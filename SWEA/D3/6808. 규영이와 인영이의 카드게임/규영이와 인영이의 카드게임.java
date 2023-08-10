import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static boolean map[];
	static boolean visited[];
	static int enemycards[];
	static int mycards[];
	static int winrate;
	static int loserate;
	
	static boolean amiwin() {
		int enemy = 0;
		int my= 0;
		for(int i= 0; i < 9; i++) {
			if (mycards[i] > enemycards[i]) {
				my  = my + mycards[i] + enemycards[i];
			}else {
				enemy  = enemy + mycards[i] + enemycards[i];
			}
		}
		
		if (my > enemy)
			return true;
		else
			return false;
	}
	
	
	
	static void dfs(int curr) {
		if (curr == 9){
			if (amiwin()) 
				winrate++;
			else
				loserate++;
			return;
		}
		
		for(int i = 1; i <= 18;i++) {
			if (visited[i])
				continue;
			if (map[i])
				continue;
			
			mycards[curr] = i;
			visited[i]= true;
			dfs(curr + 1);
			visited[i]= false;
		}
	}
	
	public static void main(String args[])throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc<= T; tc++) {
			map = new boolean[19];
			visited = new boolean[19];
			enemycards = new int[9];
			mycards = new int[9];
			winrate = 0;
			loserate = 0;
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 9;i++) {
				int card = Integer.parseInt(st.nextToken());
				enemycards[i] = card;
				map[card] = true;	
			}
			dfs(0);
			System.out.println("#"+ tc + " "+ loserate  + " "+ winrate);			
		}
	}
}