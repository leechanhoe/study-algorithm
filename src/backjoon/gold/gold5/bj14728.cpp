#include <iostream>
using namespace std;

int N, T;
pair<int, int> q[101];
int dp[10001];

int main(){
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> q[i].first >> q[i].second;
    }

    // for(int i = 1; i <= T; i++){
    //     dp[i] = dp[i-1];
    //     for(int j = 0; j < N; j++){
    //         if(i >= q[j].first){
    //             dp[i] = max(dp[i], dp[i-q[j].first] + q[j].second);
    //         }
    //     }
    // }
    for(int i = 0; i < N; i++){
        for(int j = T; j >= q[i].first; j--){
            dp[j] = max(dp[j], dp[j-q[i].first] + q[i].second);
        }
    }

    cout << dp[T];
    return 0;
}