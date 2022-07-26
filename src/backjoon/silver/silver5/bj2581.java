package backjoon.silver.silver5;
import java.io.*;

public class bj2581 {
    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int M = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        int min = 0;
        int sum = 0;

        a : for(;M <= N;M++){
            for(int i = 2;i < M;i++) {
                if (M % i == 0)
                    continue a;
            }
            if(M == 1)
                continue ;
            sum += M;
            if(min == 0)
                min = M;
        }
        if(sum == 0)
            bw.write("-1");
        else
            bw.write(sum + "\n" + min);
        bw.flush();
    }
}
