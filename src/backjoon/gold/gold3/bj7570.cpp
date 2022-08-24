#include <iostream>
using namespace std;

int dp[1000001];
int N, kid, mx;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> kid;
        dp[kid] = dp[kid-1] + 1;
        mx = max(mx, dp[kid]);
    }
    cout << N - mx;
}