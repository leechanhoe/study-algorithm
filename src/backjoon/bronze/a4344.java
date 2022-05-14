package backjoon.bronze;
import java.util.*;
import java.io.*;

class a4344
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int i = 0;i < n;i++){
            String[] input = br.readLine().split(" ");
            int studentNum = Integer.parseInt(input[0]);
            int[] scores = new int[input.length - 1];
            int sum = 0;

            for(int j = 0;j < input.length - 1;j++){
                scores[j] = Integer.parseInt(input[j + 1]);
                sum += scores[j];
            }

            float avg = (float)sum / scores.length;
            int goodStudentNum = 0;
            for(int j = 0;j < scores.length;j++){
                if(avg < scores[j])
                    goodStudentNum++;
            }
            System.out.printf("%.3f", (float)goodStudentNum / scores.length * 100);
            System.out.println("%");
        }
    }
}