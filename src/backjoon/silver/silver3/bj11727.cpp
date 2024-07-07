#include <iostream>
using namespace std;

int dp[1001];
int n;

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }

    cout << dp[n];
    return 0;
}