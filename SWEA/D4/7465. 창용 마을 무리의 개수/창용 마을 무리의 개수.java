import java.sql.SQLOutput;
import java.util.*;
import java.io.*;
public class Solution {
    static void bfs(int idx, int cnt, int visited[], ArrayList<Integer> graph[]){
        Deque<Integer> queue = new LinkedList<>();
        queue.add(idx);
        while (queue.size() != 0)
        {
            int tmp = queue.poll();
            if (visited[tmp] != 0)
                continue;
            visited[tmp] = cnt;
            for (int i = 0; i < graph[tmp].size(); i++)
                queue.add(graph[tmp].get(i));
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        for (int tc = 1; tc < T + 1; tc++) {
            int N, M;
            int cnt = 0;
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            ArrayList<Integer>[] graph = new ArrayList[N + 1];
            int visited[] = new int[N + 1];

            for (int i = 0; i <= N; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < M; i++)
            {
                st = new StringTokenizer(br.readLine());
                int u, v;
                u = Integer.parseInt(st.nextToken());
                v = Integer.parseInt(st.nextToken());
                graph[u].add(v);
                graph[v].add(u);
            }
//            for (int i = 0; i <= N; i++) System.out.println(graph[i].toString());
            for (int i = 1; i <= N; i++) {
                if (visited[i] != 0)
                    continue;
                cnt += 1;
                bfs(i, cnt, visited, graph);
            }
            System.out.println("#"+ tc + " " + cnt);
        }
    }
}