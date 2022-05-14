package backjoon.bronze;
import java.util.*;
import java.io.*;

class a1110
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int input = Integer.parseInt(br.readLine());
        int newNum = -1;
        int rightNum, leftNum;
        int cycle = 0;
        int presentNum = input;
        while(true) {
            if(input == newNum)
                break;
            cycle++;
            rightNum = presentNum % 10;
            leftNum = presentNum / 10;
            newNum = (rightNum * 10) + ((rightNum + leftNum) % 10);
            presentNum = newNum;
        }
        bw.write(cycle + "");
        bw.flush();
    }
}