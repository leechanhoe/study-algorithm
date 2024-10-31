package backjoon.silver.silver5;
import java.util.*;

public class bj13909 {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int cnt = 0;
        for(int i = 1; i * i <= N; i++){
            cnt++;
        }

        System.out.print(cnt);
    }
}
