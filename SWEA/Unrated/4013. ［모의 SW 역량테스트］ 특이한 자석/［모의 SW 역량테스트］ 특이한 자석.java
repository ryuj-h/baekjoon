import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 
 * 
하나의 자석이 1 칸 회전될 때, 붙어 있는 자석은 서로 붙어 있는 날의 자성과 다를 경우에만 인력에 의해 반대 방향으로 1 칸 회전된다.

풀이 방식:
투포인터 해결방식 처럼
각 톱니를 배열로 구성하고 상 좌 우를 가르키는 인덱스 포인터를 구현한다.

4개의 자석이기

 * 
 * @author SSAFY
 *
 */

// 0      1      2      3


public class Solution {
	public static int T, K;
	public static int Gear[][] = new int [4][8];
	
	public static void rotateArray(int index,int direction) {
		if (direction == -1) {
			int tindex = 0;
			int tmp = Gear[index][tindex];
			
			for(int i = 0; i < 7; i++) {
				Gear[index][i] = Gear[index][i+1];
			}
			Gear[index][7] = tmp;
		}
		else {
			int tindex = 7;
			int tmp = Gear[index][tindex];
			
			for(int i = 7; i >= 1; i--) {
				Gear[index][i] = Gear[index][i-1];
			}
			Gear[index][0] = tmp;
		}
	}
	/**
	 * 
	 * @param index
	 * @param direction 톱니가 회전하는 방향
	 * @param directionTo 다음 회전하는 타겟? 1이면 왼쪽 2면 오른쪽 3이면 둘다
	 */
	public static void rotate(int index, int direction,int directionTo) {
		if (index - 1 >= 0 && (directionTo ==  1 || directionTo == 3)) {
			int newIndex = index -1;
			int newDirection = direction * -1;

			//만약에 내 9시 방향과 상대의 3시방향과 다르다면	
			if (Gear[index][6] != Gear[newIndex][2]) {
				rotate(newIndex,newDirection,1);		
			}
		}
		
		if (index + 1 < 4 && (directionTo == 2 || directionTo == 3)) {
			int newIndex = index + 1;
			int newDirection = direction * -1;

			////만약에 내 3시 방향과 상대의 9시방향과 다르다면
			if (Gear[index][2] != Gear[newIndex][6]) {
				rotate(newIndex,newDirection,2);		
			}
		}
		rotateArray(index,direction);
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc<=T;tc++) {
	        K = Integer.parseInt(br.readLine()); 
	        
	        for(int i = 0; i < 4; i++) {
	        	StringTokenizer st = new StringTokenizer(br.readLine());
	        	for(int j = 0; j < 8 ;j++) {
	        		Gear[i][j] = Integer.parseInt(st.nextToken());
	        	}
	        }
	        
	        for(int i =0; i < K; i++) {
	        	int index, dir;
	        	StringTokenizer st = new StringTokenizer(br.readLine());
	        	index = Integer.parseInt(st.nextToken());
	        	dir = Integer.parseInt(st.nextToken());
	        	rotate(index-1,dir,3);
	        }
	        
	        int Solution = 0;
	        for(int i =0 ;i <4; i++) {
	        	//System.out.println(Gear[i][0]);
	            if (Gear[i][0] == 1) {
	            	Solution += Math.pow(2, i);	    	
	            }
	        }
	        
	        System.out.println("#"+tc+" "+ Solution);
        }
	}
}