#include <iostream>
using namespace std;

long long dp[81];
long long ans;
int N;

int main(){
    cin >> N;
    dp[1] = 1;
    ans = 4;
    for(int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
        ans += dp[i] * 2;
    }

    cout << ans;
    return 0;
}