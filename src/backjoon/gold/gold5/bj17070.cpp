#include <bits/stdc++.h>
using namespace std;

int dp[17][17][3];
int board[17][17];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    for(int i = 1; i < N; i++){
        if (board[0][i] == 1)
            break;
        dp[0][i][0] = 1;
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            if (board[i][j] == 1)
                continue;
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
            if (board[i][j-1] == 0 && board[i-1][j] == 0)
                dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];
        }
    }
    // for (int x = 0; x < 3; x++){
    //     for(int i = 0; i < N; i++){
    //         for(int j = 0; j < N; j++){
    //             cout << dp[i][j][x] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    cout << accumulate(dp[N-1][N-1], dp[N-1][N-1] + 3, 0);
}