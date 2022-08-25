#include <bits/stdc++.h>
using namespace std;

int dp[31][1001][2];
int T, W, plums[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T >> W;
    for(int i = 1; i <= T; i++)
        cin >> plums[i];

    for(int i = 0; i <= W; i++){
        for(int j = 1; j <= T; j++){
            if(i == 0){
                dp[i][j][0] = dp[i][j-1][0] += (plums[j] == 1);
            }
            else{
                dp[i][j][0] = max(dp[i][j-1][0], dp[i-1][j-1][1]) + (plums[j] == 1);
                dp[i][j][1] = max(dp[i][j-1][1], dp[i-1][j-1][0]) + (plums[j] == 2);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= W; i++){
        ans = max(ans, dp[i][T][0]);
        ans = max(ans, dp[i][T][1]);
    }
    cout << ans;
}