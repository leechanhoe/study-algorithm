package backjoon.bronze.bronze4;
import java.util.Scanner;

public class a2525 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        a += (b + c) / 60;
        a %= 24;
        b = (b + c) % 60;
        System.out.printf("%d %d", a, b);
    }
}