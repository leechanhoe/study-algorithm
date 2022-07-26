package backjoon.bronze.bronze3;

import java.io.*;

public class bj10250 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for(int i = 0;i < t;i++) {
            String[] input = br.readLine().split(" ");
            int h = Integer.parseInt(input[0]);
            int w = Integer.parseInt(input[1]);
            int n = Integer.parseInt(input[2]);

            int x = (int) Math.ceil((double) n / h);
            int y = n % h;
            if (y == 0)
                y = h;
            int result = y * 100 + x;

            bw.write(result + "\n");
        }
        bw.flush();
    }
}