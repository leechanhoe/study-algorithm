package backjoon.bronze.bronze2;

public class bj15596 {
    long sum(int[] a) {
        long ans = 0;
        for(int i = 0;i < a.length;i++)
            ans += a[i];
        return ans;
    }
}