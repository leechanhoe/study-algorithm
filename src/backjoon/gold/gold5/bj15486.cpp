#include <iostream>
#include <algorithm>
using namespace std;

int dp[1500001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, T, P;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T >> P;
        dp[i] = max(dp[i], dp[i-1]);

        if(i + T - 1 <= N)
            dp[i+T-1] = max(dp[i-1] + P, dp[i+T-1]);
    }
    cout << dp[N] << '\n';

    // for(int i = 1; i <= N; i++)
    //     cout << dp[i] << ' ';
}