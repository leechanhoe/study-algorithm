package backjoon.bronze;
import java.util.Scanner;

public class a1330 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a > b)
            System.out.println(">");
        else if(a == b)
            System.out.println("==");
        else if(a < b)
            System.out.println("<");
    }
}