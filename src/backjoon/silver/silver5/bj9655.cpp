#include <iostream>
using namespace std;

int dp[1001];

int main(){
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    for(int i = 4; i <= N; i++){
        dp[i] = min(dp[i-1], dp[i-3]) + 1; 
    }

    cout << ((dp[N] % 2 == 0) ? "CY" : "SK");
}