package backjoon.bronze.bronze3;
import java.util.*;
import java.io.*;

class a2439
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = 1;i <= n;i++){
            for(int j = n - i;j > 0;j--)
                bw.write(" ");
            for(int j = 0;j < i;j++)
                bw.write("*");
            bw.write("\n");
        }
        bw.flush();
    }
}