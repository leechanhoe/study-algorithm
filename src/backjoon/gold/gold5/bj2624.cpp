#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, K, p, n;
    cin >> T >> K;
    vector<pair<int, int>> coins(K);

    for(int i = 0; i < K; i++){
        cin >> p >> n;
        coins[i] = {p, n};
    }

    dp[0] = 1;
    for(int i = 0; i < K; i++){
        for(int j = T; j >= 0; j--){
            for(int k = 1; k <= coins[i].second && j - coins[i].first * k >= 0; k++)
                dp[j] += dp[j - coins[i].first * k];
        }
    }
    cout << dp[T];
}