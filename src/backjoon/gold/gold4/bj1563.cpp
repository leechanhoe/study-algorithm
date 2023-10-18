#include <iostream>
using namespace std;

int N;
int dp[1001][2][3];

int main(){
    cin >> N;

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 3; j++){
            switch (j)
            {
            case 0:
                dp[i][0][0] += (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % 1000000;
                dp[i][1][0] += (dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % 1000000;
                break;
            case 1:
                dp[i][1][0] += (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % 1000000;;
                break;
            case 2:
                dp[i][0][1] += dp[i-1][0][0] % 1000000;
                dp[i][0][2] += dp[i-1][0][1] % 1000000;
                dp[i][1][1] += dp[i-1][1][0] % 1000000;
                dp[i][1][2] += dp[i-1][1][1] % 1000000;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            ans += dp[N][i][j];
        }
    }
    cout << ans % 1000000;
    return 0;
}