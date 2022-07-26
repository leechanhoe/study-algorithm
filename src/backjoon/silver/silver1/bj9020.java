package backjoon.silver.silver1;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class bj9020 {
    static boolean[] primes = new boolean[10001];

    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        loadPrime();

        for (int a = 0;a < T;a++) {
            int N = Integer.parseInt(br.readLine());
            for (int i = N / 2; i >= 2; i--) {
                if (!primes[i] && !primes[N - i]) {
                    sb.append(i).append(' ').append(N - i).append('\n');
                    break;
                }
            }
        }
        System.out.print(sb.toString());
    }

    static void loadPrime() {
        primes[0] = primes[1] = true;
        for (int i = 2; i < Math.sqrt(primes.length); i++) {
            if (primes[i])
                continue;
            for (int j = i * i; j < primes.length; j += i)
                primes[j] = true;
        }
    }
}