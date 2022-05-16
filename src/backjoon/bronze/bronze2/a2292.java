package backjoon.bronze.bronze2;
import java.io.*;

public class a2292 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int result = 0;
        int count = 0;
        int a = 0;

        while (result < n){
            a += count++;
            result = 1 + 6 * a;
        }

        bw.write(count + "");
        bw.flush();
    }
}