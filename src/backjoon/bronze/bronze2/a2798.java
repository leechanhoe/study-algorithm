package backjoon.bronze.bronze2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a2798 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input1 = br.readLine().split(" ");
        int N = Integer.parseInt(input1[0]);
        int M = Integer.parseInt(input1[1]);
        int[] nums = new int[N];

        String[] input2 = br.readLine().split(" ");
        for(int i = 0;i < N;i++)
            nums[i] = Integer.parseInt(input2[i]);

        int minDifference = 300000;
        int ans = 0;
        for(int i = 0;i < N;i++) {
            for (int j = i + 1;j < N;j++){
                for(int k = j + 1;k < N;k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    int difference = Math.abs(sum - M);
                    if(difference < minDifference && sum <= M) {
                        minDifference = difference;
                        ans = sum;
                    }
                }
            }
        }
        bw.write(ans + "");
        bw.flush();
    }
}