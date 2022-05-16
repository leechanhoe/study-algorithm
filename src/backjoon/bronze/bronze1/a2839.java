package backjoon.bronze.bronze1;
import java.io.*;

public class a2839 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        if (n == 4 || n == 7){
            bw.write("-1");
            bw.flush();
            return;
        }

        int result = n / 5;

        switch (n % 5) {
            case 1:
            case 3:
                result += 1;
                break;
            case 2:
            case 4:
                result += 2;
                break;
        }
        bw.write(result + "");
        bw.flush();
    }
}