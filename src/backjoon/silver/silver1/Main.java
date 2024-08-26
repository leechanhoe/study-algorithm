import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int num[] = new int[M];

        int le = 1;
        int ri = 1;
        for(int i = 0; i < M; i++){
            num[i] = sc.nextInt();
            ri = Math.max(ri, num[i]);
        }

        int ans = 0;
        while(le <= ri){
            int mid = (le + ri) / 2;
            if(is_ok(mid, N, M, num)){
                ri = mid - 1;
                ans = mid;
            }
            else{
                le = mid + 1;
            }
        }

        System.out.println(ans);
    }

    static boolean is_ok(int mid, int N, int M, int[] num){
        int sum = 0;
        for(int i = 0; i < M; i++){
            sum += num[i] / mid;
            if(num[i] % mid != 0){
                sum++;
            }
        }
        return sum <= N;
    }
}