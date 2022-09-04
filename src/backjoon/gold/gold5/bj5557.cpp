#include<iostream>
#include<vector>
using namespace std;

int N;
int arr[101];
long long dp[101][21];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    dp[0][arr[0]] = 1;
    for(int i = 1; i < N - 1; i++){
        for(int j = 0; j < 21; j++){
            if(arr[i] + j <= 20){
                dp[i][arr[i]+j] += dp[i-1][j];
            }
            if(j - arr[i] >= 0){
                dp[i][j-arr[i]] += dp[i-1][j];
            }
        }
    }
    cout << dp[N-2][arr[N-1]];
}