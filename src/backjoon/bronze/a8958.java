package backjoon.bronze;
import java.util.*;
import java.io.*;

class a8958
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        String ox;

        for (int i = 0;i < n;i++){
            ox = br.readLine();
            int prevO = 0;
            int score = 0;
            for (int j = 0;j < ox.length();j++){
                if(ox.charAt(j) == 'O')
                    score += ++prevO;
                else if(ox.charAt(j) == 'X')
                    prevO = 0;
            }
            bw.write(score + "\n");
        }
        bw.flush();
    }
}