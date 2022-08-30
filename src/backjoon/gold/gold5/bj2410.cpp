#include <bits/stdc++.h>
#define MOD 1000000000;
using namespace std;

int dp[1000001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        if (i % 2 != 0){
            dp[i] = dp[i-1] % MOD;
        }
        else
            dp[i] = (dp[i/2] + dp[i-1]) % MOD;
    }
    cout << dp[N];
}