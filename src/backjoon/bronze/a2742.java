package backjoon.bronze;
import java.util.*;
import java.io.*;

class a2742
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = n;i > 0;i--)
            bw.write(i + "\n");
        bw.flush();
    }
}