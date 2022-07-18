package backjoon.bronze.bronze2;
import java.util.*;
import java.io.*;

class a3052
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        ArrayList mods = new ArrayList();
        for(int i = 0;i < 10;i++){
            int mod = Integer.parseInt(br.readLine()) % 42;
            if(!mods.contains(mod))
                mods.add(mod);
        }

        bw.write(mods.size() + "");
        bw.flush();
    }
}