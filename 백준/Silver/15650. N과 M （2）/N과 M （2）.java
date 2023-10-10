import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int N,M;
	static int []arr;
	static StringBuilder sb=new StringBuilder();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		arr=new int[M];
		// 숫자 범위는 1~N
		// 그 중 중복없이 M개를 뽑으며 순서 고려X -> start값이 계속 바뀌게됨
		
		// 입력값 arr 안쓰고 for문 변수로 해도 될듯?
		recursive(0, 1);
		System.out.println(sb);
	}
	static void recursive(int idx, int start) {
		// 종료 조건
		if(idx==M) {
			for(int i=0; i<M; i++) {
				sb.append(arr[i]).append(' ');
			}
			sb.append('\n');
//			System.out.println(Arrays.toString(arr));
			return;
		}
		for(int i=start; i<=N; i++) {
			//start~N
			arr[idx]=i;
			recursive(idx+1, i+1);
		}
	}

}