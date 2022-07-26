package backjoon.silver.silver2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class bj18870 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int[] input = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i < N;i++)
            input[i] = Integer.parseInt(st.nextToken());

        int[] sortedNums = input.clone();
        Arrays.sort(sortedNums);
        HashMap<Integer,Integer> rankingMap = new HashMap<Integer,Integer>();

        int rank = 0;
        for(int v : sortedNums){
            if(!rankingMap.containsKey(v))
                rankingMap.put(v, rank++);
        }

        StringBuilder sb = new StringBuilder();
        for(int key : input)
            sb.append(rankingMap.get(key)).append(' ');
        bw.write(sb.toString());
        bw.flush();
    }
}