import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static StringBuilder sb = new StringBuilder();
	public static boolean isPrime(int num) {
        if (num < 2) return false;

        for (int i=2; i<=Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void dfs(int output, int n) {
        if (n == 0) {
            if (isPrime(output)) sb.append(output).append("\n");
            return;
        }
        for (int i=0; i<10; i++) {
            int next = output * 10 + i;
            if (isPrime(next)) dfs(next, n - 1);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dfs(0,n);
        System.out.println(sb);
    }
}

/*
 * 실패한 코드 에라토스 
 * import java.util.ArrayList;
import java.util.Scanner;

public class BOJ2023 {
	
    public static boolean isPrime(int num) {
        if (num < 2) return false;

        for (int i=2; i<=Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
	
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int n = sc.nextInt();
		int Maxnum = 1;
		int Minimum = 0;
		for(int i = 0; i < n; i++) {
			Maxnum = Maxnum * 10;
		}
		Minimum = Maxnum / 10;
		ArrayList<Integer> list = new ArrayList<Integer>();
		int[] number = new int[Maxnum+1];
        for(int i=2; i<=Maxnum; i++) {
            number[i] = i;
        }     
        for(int i=2; i<=Maxnum; i++) {
            if(number[i]==0) continue;
            for(int j= 2*i; j<=Maxnum; j += i) {
                number[j] = 0;
            }
        }
        for(int i=Minimum; i<Maxnum; i++) {
            if(number[i]!=0) {
            	list.add(number[i]);
            }
        }  
        for(int number1 : list) {
        	int divnum = Maxnum;
        	boolean allpass = true;
        	for(int i = 0; i< n; i++) {
        		divnum = divnum / 10;
        		int checknumber = number1 / divnum;
        		
        		if (number[checknumber] == 0){
        			allpass = false;
        			break;
        		}
        	}
        	if (allpass) {
        		sb.append(number1 + "\n");
        	}
        }
        System.out.println(sb);
	}
}

*/