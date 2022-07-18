package backjoon.bronze.bronze1;

import java.io.*;

public class a2775 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for (int i = 0;i < t;i++){
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());
            int[][] apart = new int[k+1][n];

            for (int j = 0;j < n;j++)
                apart[0][j] = j + 1;

            for (int j = 1;j <= k;j++){
                for (int a = 0;a < n;a++) {
                    if(a == 0)
                        apart[j][a] = 1;
                    else
                        apart[j][a] = apart[j-1][a] + apart[j][a-1];
                }
            }
            bw.write(apart[k][n-1] + "\n");
        }
        bw.flush();
    }
}
