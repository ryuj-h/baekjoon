import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	//버튼 ABC 초단위로 변경
	static int arr[] = {60* 5, 60*1, 10};//A, B,C
	static int solutionarr[]= new int [3];
	static int t;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());
		
		
		for(int i =0; i < 3; i++) {
			//해답 배열에는 몫을 할당, t는 몫을 뺀 나머지를 재할당 하여 다음 버튼이 해결하도록 만듬
			solutionarr[i] = t / arr[i];
			t = t% arr[i];
		}
		
		
		if (t == 0) {//t가 0인경우 해결을 했기 때문에
			for(int i =0; i < 3; i++) {//해답 배열에 있는 내용 출력
				System.out.printf("%d ",solutionarr[i]);
			}
		}
		else {//아닐경우 -1 출력
			System.out.printf("-1");
		}
		
	}
}