package backjoon.bronze.bronze3;
import java.io.*;

class bj2741
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = 1;i <= n;i++)
            bw.write(i + "\n");
        bw.flush();
    }
}