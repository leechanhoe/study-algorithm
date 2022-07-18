package backjoon.bronze.bronze3;
import java.util.*;
import java.io.*;

class a10951
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int a, b;
        String input;
        while((input = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(input);
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            bw.write(a + b + "\n");
        }
        bw.flush();
    }
}