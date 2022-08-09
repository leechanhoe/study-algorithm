#include <iostream>
#include <string.h>
#define MOD 1000000003
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    int **dp = new int*[N+1];
    for (int i = 0; i <= N; i++){
        dp[i] = new int[N+1];
        memset(dp[i], 0, sizeof(int) * (N + 1));
        dp[i][0] = 1;
        dp[i][1] = i;
    }


    for (int i = 2; i <= N; i++){
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
    }

    cout << (dp[N-3][K-1] + dp[N-1][K]) % MOD;
}