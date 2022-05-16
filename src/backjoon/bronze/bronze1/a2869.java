package backjoon.bronze.bronze1;

import java.io.*;

public class a2869 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int v = Integer.parseInt(input[2]);
        int day = (int) (Math.ceil((double)(v - a) / (a - b)) + 1);

        bw.write(day + "");
        bw.flush();
    }
}