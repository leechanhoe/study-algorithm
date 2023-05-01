#include <iostream>
using namespace std;

char board[1001][1001];
int N;
int la, ra, le, re, h;
pair<int, int> heart;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
            if(board[i][j] == '*' && heart.first == 0){
                heart = {i+1, j};
            }
        }
    }

    for(int i = heart.second - 1; i > 0; i--){
        if(board[heart.first][i] == '*')
            la++;
        else
            break;
    }
    for(int i = heart.second + 1; i <= N; i++){
        if(board[heart.first][i] == '*')
            ra++;
        else
            break;
    }
    for(int i = heart.first+1; i <= N; i++){
        if(board[i][heart.second] == '*')
            h++;
        else
            break;
    }
    for(int i = 1; i <= N; i++){
        if(board[i][heart.second-1] == '*')
            le++;
    }
    le--;
    for(int i = 1; i <= N; i++){
        if(board[i][heart.second+1] == '*')
            re++;
    }
    re--;

    cout << heart.first << ' ' << heart.second << '\n';
    cout << la << ' ' << ra << ' ' << h << ' ' << le << ' ' << re;
    return 0;
}