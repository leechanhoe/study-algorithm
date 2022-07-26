package backjoon.bronze.bronze2;

import java.io.*;

public class bj10809 {
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int alphabet[] = new int[26];
        for(int i = 0;i < 26;i++)
            alphabet[i] = -1;

        int j = 0;
        for(byte value : br.readLine().getBytes()){
            if(alphabet[value - 'a'] == -1)
                alphabet[value - 'a'] = j;
            j++;
        }

        for(int i = 0;i < 26;i++)
            bw.write(alphabet[i] + " ");
        bw.flush();
    }
}
