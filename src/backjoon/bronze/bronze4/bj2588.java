package backjoon.bronze.bronze4;
import java.util.Scanner;
public class a2588
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int e3 =  a * (b % 10);
        int e4 = a * ((b / 10) % 10);
        int e5 = a * ((b / 100) % 10);
        int e6 = e3 + (e4 * 10) + (e5 * 100);
        System.out.println(e3);
        System.out.println(e4);
        System.out.println(e5);
        System.out.println(e6);
    }
}