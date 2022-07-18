package backjoon.bronze.bronze1;

import java.io.*;

public class a1193 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int x = Integer.parseInt(br.readLine());
        int denominator = 1;
        int numerator = 1;
        int sum = 0;
        int i = 0;

        while (sum < x)
            sum += ++i;

        int value = sum - x;
        if (i % 2 == 1) {
            denominator = i - (value);
            numerator += value;
        }
        else {
            numerator = i - (value);
            denominator += value;
        }

        bw.write(numerator + "/" + denominator);
        bw.flush();
    }
}