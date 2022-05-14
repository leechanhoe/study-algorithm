package backjoon.bronze;

import java.io.*;
import java.util.StringTokenizer;

public class a2675 {
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0;i < n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            String p = st.nextToken();
            for (int j = 0;j < p.length();j++) {
                for (int k = 0; k < r; k++)
                    bw.write(p.charAt(j));
            }
            bw.write("\n");
        }
        bw.flush();
    }
}
