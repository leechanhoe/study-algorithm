#include <iostream>
using namespace std;

int dp[41];
bool fix[41];
int N, M;

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int seat;
        cin >> seat;
        fix[seat] = true;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        if(fix[i] || fix[i-1]){
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = dp[i-1] + dp[i-2];
        }
    }
    cout << dp[N];
}