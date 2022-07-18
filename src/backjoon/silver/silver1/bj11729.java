package backjoon.silver.silver1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a11729 {
    static StringBuilder sb = new StringBuilder();
    static int count = 0;

    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        hanoi(N, 1, 2, 3);
        sb.insert(0,count + "\n");
        bw.write(sb.toString());
        bw.flush();
    }

    static void hanoi(int n, int from, int middle, int to) {
        if (n == 1) {
            sb.append(from).append(' ').append(to).append('\n');
            count++;
            return;
        }
        hanoi(n - 1, from, to, middle);
        hanoi(1, from, middle, to);
        hanoi(n - 1, middle, from, to);
    }
}