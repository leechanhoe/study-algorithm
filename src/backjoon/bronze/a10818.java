package backjoon.bronze;
import java.util.*;
import java.io.*;

class a10818
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i < n;i++)
            arr[i] = Integer.parseInt(st.nextToken());

        int max = arr[0];
        int min = arr[0];
        for(int i = 0;i < n;i++){
            if(arr[i] > max)
                max = arr[i];
            if(arr[i] < min)
                min = arr[i];
        }

        bw.write(min + " " + max);
        bw.flush();
    }
}