#include <iostream>
#include <vector>
using namespace std;

int blue, white;

void div_conq(int r, int c, int n, vector<vector<int>>& board){
    int cnt = 0;
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(board[i][j]){
                cnt++;
            }
        }
    }

    if(cnt == 0){
        white++;
    }
    else if(cnt == n * n){
        blue++;
    }
    else{
        int half = n / 2;
        div_conq(r, c, half, board);  // left top
		div_conq(r, c + half, half, board); // right top
		div_conq(r + half, c, half, board); // left bottom
		div_conq(r + half, c + half, half, board); // right bottom
    }
}

int main(){
    int N;

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    div_conq(0, 0, N, board);
    cout << white << '\n' << blue;
    return 0;
}