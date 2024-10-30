package backjoon.gold.gold1;
import java.io.*;
import java.util.*;

public class bj17472 {
    static int n, m;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    static int[][] board;
    static boolean[][] visited;
    static ArrayList<Node>[] list;
    static PriorityQueue<Mst_Node> pq;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String str = bf.readLine();
        StringTokenizer st = new StringTokenizer(str);

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n][m];
        for(int i = 0; i < n; i++) {
            str = bf.readLine();
            st = new StringTokenizer(str);
            for(int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        list = new ArrayList[7];
        visited = new boolean[n][m];
        int num = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 1){
                    list[num] = new ArrayList<>();
                    bfs(i, j, num);
                    num++;
                }
            }
        }

        pq = new PriorityQueue<>();
        for(int i = 1; i < num; i++){
            for(int j = 0; j < list[i].size(); j++){
                Node island = list[i].get(j);
                for(int k = 0; k < 4; k++){
                    find_bridge(island.x, island.y, i, k, -1);
                }
            }
        }

        System.out.println(kruskal(num));
    }

    public static int kruskal(int num){
        parent = new int[num];
        for(int i = 1; i < num; i++){
            parent[i] = i;
        }

        boolean[] link = new boolean[num];
        int result = 0;
        int bridge = 0;
        while(!pq.isEmpty()){
            Mst_Node current = pq.poll();

            int p1 = find(current.n1);
            int p2 = find(current.n2);

            if(p1 != p2){
                union(p1, p2);
                link[current.n1] = true;
                link[current.n2] = true;
                result += current.length;
                bridge++;
            }
        }

        if(result == 0){
            return -1;
        }
        if(bridge != num - 2){
            return -1;
        }
        return result;
    }

    public static int find(int node){
        if(parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    public static void union(int a, int b){
        parent[a] = b;
    }

    public static void find_bridge(int x, int y, int num, int dir, int len){
        if(board[x][y] != 0 && board[x][y] != num){
            if(len >= 2){
                pq.offer(new Mst_Node(num, board[x][y], len));
            }
            return;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) return;
        if(board[nx][ny] == num) return;
        find_bridge(nx, ny, num, dir, len + 1);
    }

    public static void bfs(int x, int y, int num){
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(x, y));
        visited[x][y] = true;

        while(!q.isEmpty()){
            Node current = q.poll();
 
            board[current.x][current.y] = num;
            list[num].add(new Node(current.x, current.y));
 
            for(int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(visited[nx][ny] || board[nx][ny] != 1) continue;
                visited[nx][ny] = true;
                q.offer(new Node(nx, ny));
            }
        }
    }

    public static class Mst_Node implements Comparable<Mst_Node> {
        int n1, n2, length;

        public Mst_Node(int n1, int n2, int length){
            this.n1 = n1;
            this.n2 = n2;
            this.length = length;
        }

        @Override
        public int compareTo(Mst_Node mst_n) {
            return this.length - mst_n.length;
        }

        
    }

    public static class Node {
        int x, y;

        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
