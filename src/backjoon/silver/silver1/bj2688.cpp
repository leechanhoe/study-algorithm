#include <iostream>
using namespace std;
long long dp[1001][10];
    int tc, N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> tc;

    for(int i = 0;i < 10; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= 1000; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k >= 0; k--)
                dp[i][j] += dp[i-1][k];
        }
    }

    for(int t = 0; t < tc; t++){
        cin >> N;

        long long ans = 0;
        for(int i = 0; i < 10; i++)
            ans += dp[N][i];
        cout << ans << '\n';
    }
    return 0;
}