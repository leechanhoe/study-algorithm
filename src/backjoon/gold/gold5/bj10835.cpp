#include <bits/stdc++.h>
using namespace std;

int dp[2010][2010];
int cards[2][2010];
int N;

int solve(int le, int ri){
    if(le == N || ri == N)
        return 0;
    if(dp[le][ri] != -1)
        return dp[le][ri];

    dp[le][ri] = 0;
    if(cards[0][le] > cards[1][ri])
        return dp[le][ri] += solve(le, ri + 1) + cards[1][ri];
    return dp[le][ri] += max(solve(le + 1, ri + 1), solve(le + 1, ri));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++)
            cin >> cards[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}