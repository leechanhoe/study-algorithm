package backjoon.bronze;
import java.util.*;

class a2739
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 1;i < 10;i++)
            System.out.printf("%d * %d = %d\n",n , i, n * i);
    }
}