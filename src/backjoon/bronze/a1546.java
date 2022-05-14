package backjoon.bronze;
import java.util.*;
import java.io.*;

class a1546
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = 0;
        int[] scores = new int[n];
        float sum = 0;

        for (int i = 0;i < n;i++){
            scores[i] = Integer.parseInt(st.nextToken());
            if(scores[i] > max)
                max = scores[i];
        }

        for (int i = 0;i < n;i++)
            sum += (float)scores[i] / max * 100;

        bw.write((sum / (float)n) + "");
        bw.flush();
    }
}