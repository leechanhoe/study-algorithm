#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main(){
    int N;
    cin >> N;
    for (int i = 1; i < 7; i++){
        dp[i] = i;
    }

    for(int i = 7; i <= N; i++){
        for(int j = 3; i - j > 0; j++)
            dp[i] = max(dp[i], dp[i-j] * (j - 1));
    }
    cout << dp[N];
    return 0;
}