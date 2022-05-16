package backjoon.bronze.bronze2;
import java.util.*;
import java.io.*;

class a2577
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int abc = a * b * c;
        int arr[] = new int[10];

        while (abc != 0){
            arr[abc % 10]++;
            abc /= 10;
        }

        for(int i = 0;i < 10;i++)
            bw.write(arr[i] + "\n");
        bw.flush();
    }
}