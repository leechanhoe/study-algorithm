package backjoon.bronze.bronze2;

import java.io.*;
import java.util.Scanner;

public class bj10811 {
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[sc.nextInt()];
        for(int i = 0; i < arr.length; i++){
            arr[i] = i + 1;
        }

        int N = sc.nextInt();
        for(int i = 0 ; i < N; i++){
            int le = sc.nextInt() - 1;
            int ri = sc.nextInt() - 1;

            while(le < ri){
                int tmp = arr[le];
                arr[le++] = arr[ri];
                arr[ri--] = tmp;
            }
        }
        String ans = "";
        for(int j = 0; j < arr.length; j++){
            ans += arr[j] + " ";
        }
        System.out.println(ans.trim());
        sc.close();
    }
}
