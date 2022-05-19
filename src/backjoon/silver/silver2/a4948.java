package backjoon.silver.silver2;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class a4948 {
    static boolean[] primes = new boolean[123456 * 2 + 1];
    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        loadPrime();
        while (true) {
            int N = Integer.parseInt(br.readLine());
            if(N == 0){
                System.out.print(sb.toString());
                return;
            }
            int count = 0;

            for (int i = N + 1; i <= N * 2; i++) {
                if(!primes[i])
                    count++;
            }
            sb.append(count).append('\n');
        }
    }

    static void loadPrime(){
        primes[0] = primes[1] = true;
        for (int i = 2; i <= Math.sqrt(primes.length); i++) {
            if(primes[i])
                continue;
            for(int j = i * i;j <= primes.length;j += i)
                primes[j] = true;
        }
    }
}