import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	static int arr[];
	static int arr2[];
	static boolean visited[];
	
	static void dfs(int curr, int max) {
		
		if (curr == 7){
			if (max == 100){
				for(int i =0; i< 7; i++) {
					System.out.println(arr[i]);
				}
				System.exit(0);
			}
			return;
		}
		
		for(int i = 0; i < 10;i++) {
			arr[curr] = arr2[i];
			if (visited[i])
				return;
			visited[i]= true;
			dfs(curr + 1,max + arr2[i]);
			visited[i]= false;
		}
	}
	
	public static void main(String args[]) throws IOException{
		arr = new int [8];
		arr2 = new int [10];
		visited = new boolean[10];
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		
		for(int i =0; i < 9; i++) {
			arr2[i] = Integer.parseInt(br.readLine());
		}
		
		dfs(0,0);
	}
}