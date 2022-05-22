package backjoon.silver.silver5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class a1018 {
    static char[][][] chess = new char[2][8][8];
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        char[][] board = new char[N][M];

        loadChess();

        for(int i = 0;i < N;i++){
            String input = br.readLine();
            for(int j = 0;j < M;j++)
                board[i][j] = input.charAt(j);
        }

        int min = Integer.MAX_VALUE;
        for(int i = 0;i < N - 7;i++){
            for(int j = 0;j < M - 7;j++) {
                for(int k = 0;k < 2;k++) {
                    int reDraw = 0;
                    for (int a = 0; a < 8; a++) {
                        for (int b = 0; b < 8; b++) {
                            if (board[i + a][j + b] != chess[k][a][b])
                                reDraw++;
                        }
                    }
                    if (reDraw < min)
                        min = reDraw;
                }
            }
        }

        bw.write(min + "");
        bw.flush();
    }

    static void loadChess(){
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++) {
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                    chess[0][i][j] = 'B';
                    chess[1][i][j] = 'W';
                }
                else if((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1)){
                    chess[0][i][j] = 'W';
                    chess[1][i][j] = 'B';
                }
            }
        }
    }
}
