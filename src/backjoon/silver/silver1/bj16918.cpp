#include <iostream>
using namespace std;

int R, C, N;
int board[201][201];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main(){
    cin >> R >> C >> N;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            char a;
            cin >> a;
            if(a == 'O')
                board[i][j] = 1;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(board[r][c] == 3){
                    for(int d = 0; d < 4; d++){
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if(0 <= nr && nr < R && 0 <= nc && nc < C && board[nr][nc] != 3){
                            board[nr][nc] = 0;
                        }
                    }
                    board[r][c] = 0;
                }
                else if(board[r][c])
                    board[r][c]++;
                else{    
                    if(i % 2 == 0){
                        board[r][c] = 1;
                    }
                }
            }
        }
    }
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cout << (board[r][c] ? 'O' : '.');
        }
        cout << '\n';
    }
}