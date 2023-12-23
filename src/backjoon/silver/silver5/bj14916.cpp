#include <iostream>
#define INF 987654321
using namespace std;

int n;
int dp[100001];

int main(){
    cin >> n;
    dp[1] = INF;
    for(int i = 2; i <= n; i++){
        dp[i] = INF;
        if (2 <= i && dp[i - 2] != INF)
        {
            dp[i] = dp[i-2] + 1;
        }
        if (5 <= i && dp[i - 5] != INF)
        {
            dp[i] = min(dp[i], dp[i-5] + 1);
        }
    }
    cout << (dp[n] == INF ? -1 : dp[n]);
    return 0;
}