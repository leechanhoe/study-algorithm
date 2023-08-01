#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int board[1001][1001];
int dp[1001][1001];
int ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(1){
        memset(dp, 0, sizeof(dp));

        ans = 0;
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                cin >> board[i][j];
                dp[i][j] = board[i][j];
                ans = max(ans, dp[i][j]);
            }
        }

        for(int i = 2; i <= N; i++){
            for(int j = 2; j <= M; j++){
                if(board[i][j]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}