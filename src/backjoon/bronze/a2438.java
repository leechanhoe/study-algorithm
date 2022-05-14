package backjoon.bronze;
import java.util.*;
import java.io.*;

class a2438
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < i;j++)
                bw.write("*");
            bw.write("\n");
        }
        bw.flush();
    }
}