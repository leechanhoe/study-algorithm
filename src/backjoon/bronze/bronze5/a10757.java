package backjoon.bronze.bronze5;
import java.io.*;

public class a10757 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        String a = input[0];
        String b = input[1];
        int aLen = a.length();
        int bLen = b.length();
        if(aLen > bLen) {
            for(int i = 0;i < Math.abs(aLen-bLen);i++)
                b = "0" + b;
        }
        else {
            for(int i = 0;i < Math.abs(aLen-bLen);i++)
                a = "0" + a;
        }

        int ceil = 0;
        String ans = "";
        for(int i = a.length() - 1;i >= 0;i--){
            int result = a.charAt(i) - '0' + b.charAt(i) - '0' + ceil;
            if(result > 9) {
                ceil = 1;
                result %= 10;
            }
            else
                ceil = 0;
            ans = result + ans;
        }
        if(ceil == 1)
            ans = "1" + ans;
        System.out.println(ans);
    }
}