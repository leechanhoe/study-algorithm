package backjoon.bronze.bronze4;
import java.io.*;
import java.util.StringTokenizer;

public class a1712 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        if(b == c) {
            bw.write("-1");
            bw.flush();
            return;
        }
        int result = a/(c - b);

        if(result < 0)
            result = -2;

        bw.write((result + 1) + "");
        bw.flush();
    }
}