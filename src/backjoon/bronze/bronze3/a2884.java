package backjoon.bronze.bronze3;
import java.util.Scanner;

public class a2884 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int m = sc.nextInt();
        if(m - 45 < 0){
            m += 15;
            h -= 1;
            if(h < 0)
                h = 23;
        }
        else
            m -= 45;
        System.out.printf("%d %d", h, m);
    }
}