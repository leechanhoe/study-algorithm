package backjoon.silver;
import java.util.*;
import java.io.*;

class a4673
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] numArr = new int[10001];

        for(int i = 1;i <= 10000;i++){
            int selfNum = selfNumber(i);
            if(selfNum <= 10000)
                numArr[selfNum]++;
        }

        for(int i = 1;i <= 10000;i++){
            if(numArr[i] == 0)
                bw.write(i + "\n");
        }
        bw.flush();
    }

    static int selfNumber(int n) {
        int result = n;
        while(n != 0){
            result += n % 10;
            n /= 10;
        }
        return result;
    }
}