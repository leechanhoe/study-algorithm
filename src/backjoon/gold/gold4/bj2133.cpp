#include <iostream>
using namespace std;

int N;
int dp[31];

int main(){
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= N; i += 2){
        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i-j] * 2;
        dp[i] += dp[i-2] * 3;
    }
    cout << dp[N];
}