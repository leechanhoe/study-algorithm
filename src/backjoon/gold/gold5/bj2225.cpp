#include <iostream>
using namespace std;

int N, K;
int dp[201][201];

int main(){
    cin >> N >> K;

    for (int i = 0; i <= N; i++){
        dp[i][1] = 1;
        for(int j = 2; j <= K; j++){
            for(int k = 0; k <= i; k++){
                dp[i][j] = (dp[i][j] + dp[k][j-1]) % 1000000000;
            }
        }
    }
    cout << dp[N][K];
}