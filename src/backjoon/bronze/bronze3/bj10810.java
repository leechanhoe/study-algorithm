package backjoon.bronze.bronze3;
import java.util.*;

public class bj10810 {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] arr = new int[N];
		
		for(int i = 0; i < M; i++){
		    int start = sc.nextInt();
		    int end = sc.nextInt();
		    int ball = sc.nextInt();
		    
		    for(int j = start - 1; j < end; j++){
		        arr[j] = ball;
		    }
		}
		
		for(int i = 0; i < N; i++){
		    System.out.print(arr[i] + " ");
		}
	}
}