package backjoon.bronze.bronze2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a10870 {
    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        bw.write(fibonacci(N) + "");
        bw.flush();
    }

    static int fibonacci(int n){
        if(n == 1)
            return 1;
        if(n == 0)
            return 0;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
