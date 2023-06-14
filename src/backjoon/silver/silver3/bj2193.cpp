#include <iostream>
using namespace std;

long long dp[91][2];
int N;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1][1] = 1;
    for(int i = 2; i <= N; i++){
        dp[i][0] += dp[i-1][0];
        dp[i][0] += dp[i-1][1];
        dp[i][1] += dp[i-1][0];
    }

    cout << (dp[N][0] + dp[N][1]);
}