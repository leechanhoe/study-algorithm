package backjoon.bronze.bronze3;
import java.io.*;
import java.util.StringTokenizer;

public class bj2914 {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int I = Integer.parseInt(st.nextToken());

        bw.write(String.valueOf(A * (I - 1) + 1));
        bw.flush();
        bw.close();
    }
}
