#include <iostream>
#include <string>
using namespace std;

int tc, t;
string board[3];

void solve(){
    for(int i = 0; i < 3; i++){
        string input;
        cin >> input;
        board[i] = input;
    }

    char ox;
    int num = 0;
    cin >> ox;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ox){
                num++;
            }
        }
        if (num == 2){
            for(int j = 0; j < 3; j++){
                board[i][j] = ox;
            }
            return;
        }
        num = 0;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[j][i] == ox){
                num++;
            }
        }
        if (num == 2){
            for(int j = 0; j < 3; j++){
                board[j][i] = ox;
            }
            return;
        }
        num = 0;
    }

    for(int i = 0; i < 3; i++){
        if(board[i][i] == ox){
            num++;
        }
    }

    if (num == 2){
        for(int j = 0; j < 3; j++){
            board[j][j] = ox;
        }
        return;
    }
    num = 0;

    for(int i = 0; i < 3; i++){
        if(board[i][2-i] == ox){
            num++;
        }
    }
    if (num == 2){
        for(int j = 0; j < 3; j++){
            board[j][2-j] = ox;
        }
        return;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> tc;
    
    while(++t <= tc){
        solve();

        cout << "Case " << t << ":\n";
        for(int j = 0; j < 3; j++){
            cout << board[j] << '\n';
        }
    }
}