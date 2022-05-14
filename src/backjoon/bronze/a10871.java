package backjoon.bronze;
import java.util.*;
import java.io.*;

class a10871
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        String[] nums = br.readLine().split(" ");
        for(int i = 0;i < nums.length;i++){
            if(Integer.parseInt(nums[i]) < x)
                bw.write(nums[i] + " ");
        }
        bw.flush();
    }
}