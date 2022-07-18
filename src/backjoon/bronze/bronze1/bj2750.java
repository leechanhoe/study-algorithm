package backjoon.bronze.bronze1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a2750 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        for(int i = 0;i < N;i++)
            arr[i] = Integer.parseInt(br.readLine());

        bubbleSort(arr);

        for(int i = 0;i < N;i++)
            bw.write(arr[i] + "\n");
        bw.flush();
    }

    static void insertionSort(int[] arr){
        for(int i = 1;i < arr.length;i++){
            int key = arr[i];
            int j;
            for(j = i - 1;j >= 0 && arr[j] > key;j--)
                arr[j+1] = arr[j];
            arr[++j] = key;
        }
    }

    static void bubbleSort(int[] arr){
        for(int i = arr.length - 1;i >= 0;i--) {
            for (int j = 0;j < i ; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}