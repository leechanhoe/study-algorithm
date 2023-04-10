package backjoon.bronze.bronze5;
import java.util.*;

public class bj27433
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    long N = sc.nextLong();
		System.out.println(f(N));
	}
	
	static long f(long n){
	    if(n == 0)
	        return 1;
	    return n * f(n - 1);
	}
}