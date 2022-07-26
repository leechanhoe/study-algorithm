package backjoon.bronze.bronze3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class bj10872 {
    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        bw.write(factorial(N) + "");
        bw.flush();
    }

    static int factorial(int n){
        if(n <= 1)
            return 1;
        return n * factorial(n - 1);
    }
}
