package backjoon.bronze;
import java.util.Scanner;

public class a2480 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        if(a == b && a == c && b == c)
            System.out.println(10000 + (a * 1000));
        else if(a == b || a == c)
            System.out.println(1000 + (a * 100));
        else if(b == c)
            System.out.println(1000 + (b * 100));
        else {
            int max= 0;
            if(a > b && a > c)
                max = a;
            else if(b > a && b > c)
                max = b;
            else if(c > a && c > b)
                max = c;
            System.out.println(max * 100);
        }
    }
}