package backjoon.silver.silver4;
import java.io.*;

class bj1065
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int count = 0;

        for(int i = 1;i <= n;i++) {
            if (selfNumber(i))
                count++;
        }
        bw.write(count + "");
        bw.flush();
    }
    static boolean selfNumber(int n) {
        if(n < 100)
            return true;
        if(n == 1000)
            return false;

        int[] digit = new int[3];
        for(int i = 0;i < 3;i++) {
            digit[i] = n % 10;
            n /= 10;
        }

        if(digit[2] - digit[1] == digit[1] - digit[0])
            return true;

        return false;
    }
}