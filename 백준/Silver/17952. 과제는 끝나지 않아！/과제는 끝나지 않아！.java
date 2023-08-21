import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N =  Integer.parseInt(br.readLine());
		
		//일 배열을 2차원으로 구성해줌
		int WorkList[][] = new int[N][3]; // [][0] - 1 일경우 일을 받음 [][1] - 업무 점수 A [][2] - 남은 일
		int point = 0;// 총 점수
		
		for(int i =0; i< N; i++) {
			StringTokenizer st = new StringTokenizer (br.readLine());
			WorkList[i][0] = Integer.parseInt(st.nextToken());
			
			if (WorkList[i][0] != 0) {//일을 받았다면 해당 정보 입력을 받음
				WorkList[i][1] = Integer.parseInt(st.nextToken());
				WorkList[i][2] = Integer.parseInt(st.nextToken());	
			}
			for(int j = i; j >= 0 ;j--) {//for 문을 맨 뒤에서부터 시작하여 배열의 첫 번째까지 반복
				if (WorkList[j][2] != 0) {// 만약 일이 남아 있다면
					WorkList[j][2] = WorkList[j][2] -1;// 그 일을 하고 1만큼 감소시켜줌
					if (WorkList[j][2] == 0) {//일을 하고 일이 끝났다면
						point += WorkList[j][1];//포인트 획득 후
						WorkList[j][1] = 0;//전체 정보 초기화
						WorkList[j][0] = 0;
					}
					break;//일을 하였기 때문에 더 이상 일을 진행하지 못함. break로 탈출하여 다음날로 반복
				}
			}
		}
		System.out.println(point);
	}
}