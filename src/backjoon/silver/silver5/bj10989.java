package backjoon.silver.silver5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class bj10989 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        for(int i = 0;i < N;i++)
            arr[i] = Integer.parseInt(br.readLine());

        arr = countingSort(arr);

        for(int i = 0;i < N;i++)
            sb.append(arr[i]).append('\n');
        bw.write(sb.toString());
        bw.flush();
    }

    static int[] countingSort(int[] arr){
        int[] count = new int[10001];
        for(int i = 0;i < arr.length;i++)
            count[arr[i]]++;

        for(int i = 1;i < count.length;i++)
            count[i] += count[i-1];

        int[] result = new int[arr.length];
        for(int i = arr.length - 1;i >= 0;i--)
            result[--count[arr[i]]] = arr[i];

        return result;
    }
}
