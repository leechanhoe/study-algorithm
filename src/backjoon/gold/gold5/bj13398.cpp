#include <bits/stdc++.h>
using namespace std;

int dp[100001][2];

int main(){
    int N, arr;
    cin >> N >> arr;

    dp[0][0] = arr;
    int ans = arr;
    for (int i = 1; i < N; i++){
        cin >> arr;
        dp[i][0] = max(dp[i-1][0] + arr, arr);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr);
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans;
}