import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
	public static int T,N,X, map[][];
	
	/**
	 * @return
	 */
	public static boolean isPosiblePath(ArrayList<Integer> currlist) {
		boolean start = true;
		boolean set[] = new boolean[N+1];
		for (int i = 0; i < N - 1; i++)
		{
			int curr = currlist.get(i);
			int next =currlist.get(i + 1);

			if (curr == next)//높이가 같으면
			{
				//아무것도 안하고 넘어감
			}
			else if (curr - next == 1)//내려가는경우
			{
				for (int j = i + 1; j <= i + X; j++)
				{
					if (j >= N)
						return false;
					if (set[j])
						return false;
					int nnext = currlist.get(j);
					if (nnext != next)
						return false;
					set[j] = true;
				}
				i = i + X - 1;
			}
			else if (curr - next == -1)//올라가는경우
			{
				for (int j = i; j >= i - X + 1; j--)
				{
					if (j < 0)
						return false;
					if (set[j])
						return false;
					int prev = currlist.get(j);
					if (prev != curr)
						return false;
					set[j] = true;
				}
			}
			else
				return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc<=T;tc++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	N = Integer.parseInt(st.nextToken());
        	X = Integer.parseInt(st.nextToken());
        	
        	map = new int[N][N];
        	for(int y= 0; y< N; y++) {
            	st = new StringTokenizer(br.readLine());
        		for(int x= 0; x< N; x++) {
        			map[y][x] = Integer.parseInt(st.nextToken());
        		}
        	}
        	
        	
        	ArrayList<Integer>Arrays[] = new ArrayList[N * N + 1];
        	int index = 0;
        	for(int y = 0 ; y < N ; y++) {
        		ArrayList <Integer> row = new ArrayList();
        		ArrayList <Integer> col = new ArrayList();
        		for(int x= 0; x < N; x++) {
        			row.add(map[y][x]);
        			col.add(map[x][y]);
        		}
        		Arrays[index++] = row;
        		Arrays[index++] = col;
        	}
        	
        	int Solution = 0;
        	for(ArrayList<Integer> currlist: Arrays) {
        		if(currlist != null) {
        			if (isPosiblePath(currlist))
        				Solution++;
	        	}
        	}
	        System.out.println("#"+tc+" "+ Solution);
        	
        }   
	}
}