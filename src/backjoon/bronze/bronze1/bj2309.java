package backjoon.bronze.bronze1;
import java.util.*;
import java.io.*;

public class bj2309 {
    public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = new int[9];
		int sum = 0;
		for(int i = 0; i < 9; i++){
		    arr[i] = Integer.parseInt(br.readLine());
		    sum += arr[i];
		}
		
		for(int i = 0; i < 9; i++){
		    for(int j = i + 1; j < 9; j++){
		        if(sum - arr[i] - arr[j] == 100){
		            arr[i] = arr[j] = 0;
		            Arrays.sort(arr);
		            for(int k = 2; k < 9; k++)
		                System.out.println(arr[k]);
		            return;
		        }
		    }
		}
	}
}
