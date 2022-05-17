package backjoon.silver.silver2;

import java.io.*;

public class a18111 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int b = Integer.parseInt(input[2]);
        int[][] ground = new int[n][m];
        int heightSum = 0;

        for (int i = 0; i < n; i++) { // 초기화
            String[] width = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                ground[i][j] = Integer.parseInt(width[j]);
                heightSum += ground[i][j];
            }
        }

        int possibleHeight = (int) Math.floor((double)(heightSum + b) / (n * m)); // 가능한 높이중 최대
        int optimunHeight = 0; // 최적의 높이
        int minTime = Integer.MAX_VALUE;// 최적의 시간

        for(int curHeight = possibleHeight;curHeight >= 0;curHeight--) { //가능한 높이들 다 땅고르기작업시도해서 최적높이 구하기
            int reqTime = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (curHeight > ground[i][j])
                        reqTime += curHeight - ground[i][j];
                    else if (curHeight < ground[i][j])
                        reqTime += (ground[i][j] - curHeight) * 2;
                }
            }
            if(minTime > reqTime){
                minTime = reqTime;
                optimunHeight = curHeight;
            }
        }
        bw.write(minTime + " " + optimunHeight);
        bw.flush();
    }
}