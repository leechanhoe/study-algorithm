package backjoon.silver.silver3;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class a1929 {
    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);
        StringBuilder sb = new StringBuilder();
        boolean[] primes = new boolean[N + 1];
        primes[0] = primes[1] = true;

        for(int i = 2;i <= Math.sqrt(N);i++) {
            if(primes[i])
                continue;
            for(int j = i * i;j <= N;j += i)
                primes[j] = true;
        }

        for(int i = M;i <= N;i++) {
            if(!primes[i])
                sb.append(i).append('\n');
        }
        System.out.print(sb.toString());
    }
}