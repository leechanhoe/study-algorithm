package backjoon.silver.silver1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class bj2447 {
    static boolean[][] stars;
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        stars = new boolean[N][N];
        loadStar(N, 0 , 0);
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(!stars[i][j])
                    sb.append('*');
                else
                    sb.append(' ');
            }
            sb.append('\n');
        }

        bw.write(sb.toString());
        bw.flush();
    }

    static void loadStar(int size, int startPointY, int startPointX){
        int blankSize = size / 3;
        for(int i = blankSize + startPointY;i < blankSize * 2 + startPointY;i++){
            for(int j = blankSize + startPointX;j < blankSize * 2 + startPointX;j++)
                stars[i][j] = true;
        }
        if(size <= 3)
            return;
        for(int i = startPointY;i < size + startPointY;i+=blankSize){
            for(int j = startPointX;j < size + startPointX;j+=blankSize) {
                if(i == blankSize + startPointY && j == blankSize + startPointX)
                    continue;
                loadStar(blankSize, i, j);
            }
        }
    }
}
