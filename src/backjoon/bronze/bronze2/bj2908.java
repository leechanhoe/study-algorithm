package backjoon.bronze.bronze2;
import java.io.*;

public class a2908 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuffer sb = new StringBuffer(br.readLine());
        String reverse = sb.reverse().toString();

        int a = Integer.parseInt(reverse.split(" ")[0]);
        int b = Integer.parseInt(reverse.split(" ")[1]);

        if(a > b)
            bw.write(a + "");
        else if(a < b)
            bw.write(b + "");

        bw.flush();
    }
}