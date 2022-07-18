package backjoon.silver.silver5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a1436 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int count = 0;
        int i = 666;
        while (count < N){
            String num = Integer.toString(i);
            for(int j = 0;j < num.length() - 2;j++){
                if(num.contains("666")) {
                    count++;
                    break;
                }
            }
            i++;
        }

        bw.write(--i + "");
        bw.flush();
    }
}