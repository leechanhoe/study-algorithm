#include <iostream>
using namespace std;

int N;
int card[1001];
int dp[1001];

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> card[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i-j] + card[j], dp[i]);
        }
    }
    cout << dp[N];
    return 0;
}