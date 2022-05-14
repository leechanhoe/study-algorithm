package backjoon.bronze;
import java.io.*;
import java.util.*;

class a11720
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br.readLine();
        int sum = 0;
        for(byte value : br.readLine().getBytes())
            sum += (value - '0');
        System.out.println(sum);
        bw.flush();
    }
}