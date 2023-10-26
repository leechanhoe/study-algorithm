#include <iostream>
using namespace std;

string board;

int main(){
    cin >> board;

    int x = 0;
    string ans = "";
    for(int i = 0; i < board.size(); i++){
        if(board[i] == 'X'){
            x++;
        }
        else{
            if(x % 2){
                cout << -1;
                return 0;
            }
            if (x == 2){
                ans += "BB";
                x = 0;
            }
            ans += '.';
        }
        if(x == 4){
            ans += "AAAA";
            x = 0;
        }
    }
    if(x == 2){
        ans += "BB";
    }
    else if(x % 2){
        cout << -1;
        return 0;
    }

    cout << ans;
    return 0;
}