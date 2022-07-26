package backjoon.bronze.bronze2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class bj2231 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        int N = Integer.parseInt(input);
        int start = N - input.length() * 9;

        for(int i = start;i < N;i++){
            int decompose = i;
            int n = i;
            while (n != 0){
                decompose += n % 10;
                n /= 10;
            }
            if(decompose == N) {
                bw.write(i + "");
                bw.flush();
                return;
            }
        }
        bw.write("0");
        bw.flush();
    }
}
