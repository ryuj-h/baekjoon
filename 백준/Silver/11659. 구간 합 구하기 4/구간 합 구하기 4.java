import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int M;
	static int arr[];
	static int sumarr[];

	static StringBuilder sb = new StringBuilder();
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine()," ");
		arr =new int[N+1];
		sumarr = new int[N+1];
		
		for(int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			sumarr[i] = sumarr[i-1] + arr[i];
		}


		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int vi = Integer.parseInt(st.nextToken());
			int vj = Integer.parseInt(st.nextToken());
			sb.append((sumarr[vj] - sumarr[vi - 1]) + "\n");
			//System.out.println(sumarr[vj] - sumarr[vi - 1]);
		}
		

		System.out.println(sb);
	}
}