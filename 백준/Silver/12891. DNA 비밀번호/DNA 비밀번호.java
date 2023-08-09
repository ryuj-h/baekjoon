import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int strlen;
	static int newstrlen;
	static char[] str;
	static int ACGT[] = new int [4];
	static int nACGT[] = new int [4];
	
	
	public static boolean check() {
		for (int i = 0; i < 4; i++) {
			if (nACGT[i]<ACGT[i])
				return false;
		}
		return true;
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		strlen = Integer.parseInt(st.nextToken());
		newstrlen = Integer.parseInt(st.nextToken());
		str = br.readLine().toCharArray();
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < 4; i++) {
			ACGT[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i <newstrlen; i++) {
			if (str[i] == 'A') nACGT[0]++;
			else if (str[i] == 'C') nACGT[1]++;
			else if (str[i] == 'G') nACGT[2]++;
			else if (str[i] == 'T') nACGT[3]++;
		}
		int solution = 0;
		if (check())
			solution++;
		
		for(int j = newstrlen; j< strlen ;j++) {
			int i = j - newstrlen; 
			
			if (str[i]=='A') nACGT[0]--;
			if (str[i]=='C') nACGT[1]--;
			if (str[i]=='G') nACGT[2]--;
			if (str[i]=='T') nACGT[3]--;
			
			if (str[j]=='A') nACGT[0]++;
			if (str[j]=='C') nACGT[1]++;
			if (str[j]=='G') nACGT[2]++;
			if (str[j]=='T') nACGT[3]++;
			

			if (check())
				solution++;
		}
		
		
		System.out.println(solution);
	}
}