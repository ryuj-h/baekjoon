import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N,M,R, T;
	static int line;
	static int map[][];
	
	public static void print_map() {		
		for(int y = 1; y <=N;y++ ) {
			for(int x = 1; x <= M;x++) {
				System.out.printf("%d ", map[y][x]);
			}
			System.out.printf("\n");
		}
	}
	
	public static void func_1() {
		for(int y = 1; y <= N/2 ; y++) {
			for(int x =1; x <= M ; x++) {
				int tmp = map[y][x];
				map[y][x] = map[N-y +1][x];
				map[N-y +1][x] = tmp;
			}
		}
	}
	public static void func_2() {
		for(int y = 1; y <= N ; y++) {
			for(int x =1; x <= M/2 ; x++) {
				int tmp = map[y][x];
				map[y][x] = map[y][M - x+1];
				map[y][M - x+1] = tmp;
			}
		}
	}
	
	public static void func_3(){
		int tmpMap [][] = new int[line+1][line+1];
 
        for(int y=1; y<=N; y++){
            for(int x=1; x<=M; x++){
                tmpMap[x][N-y + 1] =  map[y][x];
            }
        }
        int tmp = N;
        N = M;
        M= tmp;
        map = tmpMap;
    }
	
	public static void func_4(){
		int tmpMap [][] = new int[line+1][line+1];
        for(int y=1; y<=N; y++){
            for(int x=1; x<=M; x++){
                tmpMap[M-x+1][y] =  map[y][x];
            }
        }
        int tmp = N;
        N = M;
        M= tmp;
 
        map = tmpMap;
 
 
    }
    public static void func_5(){
        //5번 연산 : 4그룹 1->2, 2->3, 3->4, 4->1
    	int tMpMap [][] = new int[N+1][M+1];
        for(int i=1; i<=N/2; i++){
            for(int j=1; j <= M/2; j++){
                tMpMap[i][M/2+j] = map[i][j];
            }
        }
 
        // 0,4 -> 3,4
        for(int i=1; i<=N/2; i++){
            for(int j=M/2 +1; j<=M; j++){
                tMpMap[N/2+i][j] = map[i][j];
            }
        }
        
        // 3,4 -> 3,0
        for(int i=N/2 +1; i<=N; i++){
            for(int j=M/2 +1; j<=M; j++){
                tMpMap[i][j-M/2] = map[i][j];
            }
        }
        

        // 3,0 -> 0,0
        for(int i=N/2 +1; i<=N; i++){
            for(int j=1; j<=M/2; j++){
                tMpMap[i-N/2][j] = map[i][j];
            }
        }
        map = tMpMap;
    }
    
    public static void func_6(){
    	int tmpMap [][] = new int[N+1][M+1];
        for(int i=1; i<=N/2; i++){
            for(int j=1; j<=M/2; j++){
                tmpMap[N/2+i][j] = map[i][j];
 
            }
        }
        for(int i=N/2+1; i<=N; i++){
            for(int j=1; j<=M/2; j++){
                tmpMap[i][j+M/2] = map[i][j];
            }
        }
        for(int i=N/2; i<=N; i++){
            for(int j=M/2 +1; j<=M; j++){
                tmpMap[i-N/2][j] = map[i][j];
            }
        }
       
        for(int i=0; i<=N/2; i++){
            for(int j=M/2; j<=M; j++){
                tmpMap[i][j-M/2] = map[i][j];
            }
        }
        map = tmpMap;
    }
	
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		
		line = Math.max(N, M);
		
		
		map = new int[line+1][line+1];
		
		for(int y = 1; y <=N;y++ ) {
			st = new StringTokenizer(br.readLine());
			for(int x = 1; x <= M;x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		
		

		st = new StringTokenizer(br.readLine());
		
		for(int i = 0 ; i < R; i++) {
			T = Integer.parseInt(st.nextToken());
			if (T == 1 ) {
				func_1();
			}else if (T == 2) {
				func_2();
			}else if (T == 3) {
				func_3();
			}else if (T == 4) {
				func_4();
			}else if (T == 5) {
				func_5();
			}else if (T == 6) {
				func_6();
			}
		}
		print_map();
		
		
	}
}