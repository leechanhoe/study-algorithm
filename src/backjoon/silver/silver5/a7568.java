package backjoon.silver.silver5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class a7568 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String input = br.readLine();
        int N = Integer.parseInt(input);
        int[][] build = new int[N][2];

        for(int i = 0;i < N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            build[i][0] = Integer.parseInt(st.nextToken());
            build[i][1] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0;i < N;i++){
            int rank = 1;
            for(int j = 0;j < N;j++) {
                if (build[i][0] < build[j][0] && build[i][1] < build[j][1])
                    rank++;
            }
            sb.append(rank).append(' ');
        }

        bw.write(sb.toString());
        bw.flush();
    }
}