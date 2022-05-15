package backjoon.silver;
import java.io.*;

public class a1316 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int count = n;

        for (int i = 0;i < n;i++){
            String word = br.readLine();
            if (word.length() == 1)
                continue;

            boolean[] used = new boolean[26];
            for (int j = 0;j < word.length();j++) {
                int c = word.charAt(j) - 'a';
                if (!used[c])
                    used[c] = true;
                else{
                        if (word.charAt(j) != word.charAt(j - 1)) {
                            count--;
                            break;
                        }
                }
            }
        }
        bw.write(count + "");
        bw.flush();
    }
}