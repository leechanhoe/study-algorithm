#include <iostream>
using namespace std;

int main(){

    char board[8][8];
    int ans = 0;
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j];
            if (board[i][j] == 'F' && ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))){
                ans++;
            }
        }
    }

    cout << ans;
}