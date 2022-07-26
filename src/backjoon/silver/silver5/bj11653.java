package backjoon.silver.silver5;

import java.io.*;

public class bj11653 {
    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        if(N == 1)
            return;
        for(int i = 2;i <= N;i++){
            if(N % i == 0){
                bw.write(i + "\n");
                N /= i;
                i = 1;
            }
        }
        bw.flush();
    }
}