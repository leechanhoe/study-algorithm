package backjoon.bronze.bronze5;

import java.io.*;

public class bj27866 {
    public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = br.readLine().trim();
		int i = Integer.parseInt(br.readLine());
		
		System.out.println(s.substring(i-1, i));
	}
}
