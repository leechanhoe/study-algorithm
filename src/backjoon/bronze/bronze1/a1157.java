package backjoon.bronze.bronze1;
import java.io.*;

public class a1157 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] alphabets = new int[26];
        for (byte value : br.readLine().getBytes()) {
            if (value <= 'Z')
                alphabets[value - 'A']++;
            else
                alphabets[value - 'a']++;
        }

        int max = 0;
        int maxIndex = 0;
        boolean overlap = false;
        for (int i = 0;i < 26;i++) {
            if (alphabets[i] > max) {
                max = alphabets[i];
                maxIndex = i;
                overlap = false;
            } else if (alphabets[i] == max)
                overlap = true;
        }
        if(overlap)
            bw.write("?");
        else
            bw.write((char)('A' + maxIndex));
        bw.flush();
    }
}
