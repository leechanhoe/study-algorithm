#include <iostream>
using namespace std;

int N, K;
int I[1001];
int T[1001];
int dp[10001][1001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= K; i++){
        cin >> I[i] >> T[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            dp[i][j] = dp[i][j-1];
            if(i - T[j] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-T[j]][j-1] + I[j]);
        }
    }

    cout << dp[N][K];
    return 0;
}