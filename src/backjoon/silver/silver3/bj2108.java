package backjoon.silver.silver3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a2108 {
    static int sum = 0;
    static int[] modes= {Integer.MAX_VALUE,Integer.MAX_VALUE};

    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        for(int i = 0;i < N;i++)
            arr[i] = Integer.parseInt(br.readLine());

        arr = countingSort(arr);

        sb.append(Math.round(sum / (float)N)).append('\n');
        sb.append(arr[arr.length / 2]).append('\n');
        if(modes[1] == Integer.MAX_VALUE)
            sb.append(modes[0]);
        else
            sb.append(modes[1]);
        sb.append('\n').append(arr[arr.length - 1] - arr[0]);

        bw.write(sb.toString());
        bw.flush();
    }

    static int[] countingSort(int[] arr){
        int[] count = new int[8001];
        for(int i = 0;i < arr.length;i++) {
            count[arr[i] + 4000]++;
            sum += arr[i];
        }

        int max = Integer.MIN_VALUE;
        for(int i = 0;i < count.length;i++) {
            if (count[i] > max) {
                max = count[i];
            }
        }

        int cnt = 0;
        for(int i = 0;i < count.length && cnt < 2;i++) {
            if (count[i] == max) {
                modes[cnt] = i - 4000;
                cnt++;
            }
        }

        for(int i = 1;i < count.length;i++)
            count[i] += count[i-1];

        int[] result = new int[arr.length];
        for(int i = arr.length - 1;i >= 0;i--)
            result[--count[arr[i] + 4000]] = arr[i];

        return result;
    }
}