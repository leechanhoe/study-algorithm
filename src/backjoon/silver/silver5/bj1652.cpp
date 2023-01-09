#include <iostream>
#include <string>
using namespace std;

int N, ans, cnt;
string board[101];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> board[i];
        for(int j = 0; j < N; j++){
            if(board[i][j] == '.')
                cnt++;
            else{
                if(cnt >= 2)
                    ans++;
                cnt = 0;
            }
        }
        if(cnt >= 2)
            ans++;
        cnt = 0;
    }
    cout << ans << ' ';

    ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[j][i] == '.')
                cnt++;
            else{
                if(cnt >= 2)
                    ans++;
                cnt = 0;
            }
        }
        if(cnt >= 2)
            ans++;
        cnt = 0;
    }
    cout << ans;
    return 0;
}