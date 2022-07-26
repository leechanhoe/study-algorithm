package backjoon.bronze.bronze2;
import java.io.*;

class bj2562
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[9];

        for(int i = 0;i < 9;i++)
            arr[i] = Integer.parseInt(br.readLine());

        int max = arr[0];
        int index = 0;

        for(int i = 0;i < 9;i++){
            if(arr[i] > max){
                max = arr[i];
                index = i;
            }
        }
        bw.write(max + "\n" + (index + 1));
        bw.flush();
    }
}