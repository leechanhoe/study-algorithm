package backjoon.bronze.bronze5;
import java.util.Scanner;

public class bj9086
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int N = sc.nextInt();
	    
		for (int i = 0 ; i < N ; i++) {
            String str = sc.next();
            int l = str.length();
            String first = String.valueOf(str.charAt(0));
            String last = String.valueOf(str.charAt(l-1));
            System.out.println(first+last);
        }
	}
}