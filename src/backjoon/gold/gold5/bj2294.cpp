#include <iostream>
#define INF 987654321
using namespace std;

int coins[100];
int dp[10001];
int N, K;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    for (int i = 1; i <= K; i++){
        dp[i] = INF;
        for (int j = 0; j < N; j++){
            if (i >= coins[j])
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    if (dp[K] == INF)
        cout << -1;
    else
        cout << dp[K];
}