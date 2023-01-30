#include <iostream>
using namespace std;

char board[502][502];
int R, C;
int mv[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(board[i][j] == 'S'){
                for(auto dir : mv){
                    int nr = i + dir[0];
                    int nc = j + dir[1];
                    if(board[nr][nc] == 'W'){
                        cout << 0;
                        return 0;
                    }
                    else if(board[nr][nc] == '.')
                        board[nr][nc] = 'D'; 
                }
            }
        }
    }

    cout << "1\n";
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}