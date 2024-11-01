package Softeer.Level2;
import java.io.*;
import java.util.*;


public class 나무_공격 {
    public static final int MAX_N = 100;
    public static final int MAX_M = 100;

    public static int n, m;
    public static int[][] attackArr = new int[2][2];
    public static int[] cntArr = new int[MAX_N];
    public static int ans = 0;
    
    public static void main(String[] args) throws IOException {
        init();

        for(int i = 0; i < 2; i++){
            for(int s = attackArr[i][0]; s <= attackArr[i][1]; s++){
                if(cntArr[s] > 0){
                    cntArr[s]--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ans += cntArr[i];
        }

        System.out.println(ans);
    }

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int cnt = 0;

            for(int j = 0; j < m; j++){
                int temp = Integer.parseInt(st.nextToken());

                if(temp == 1) cnt++;
            }

            cntArr[i] = cnt;
        }

        st = new StringTokenizer(br.readLine());
        attackArr[0][0] = Integer.parseInt(st.nextToken()) - 1;
        attackArr[0][1] = Integer.parseInt(st.nextToken()) - 1;
        
        st = new StringTokenizer(br.readLine());
        attackArr[1][0] = Integer.parseInt(st.nextToken()) - 1;
        attackArr[1][1] = Integer.parseInt(st.nextToken()) - 1;
    }
}
