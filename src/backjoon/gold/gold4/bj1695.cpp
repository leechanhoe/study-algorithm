#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[5001];
int dp[5001][5001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(arr[i-1] != arr[N-j]){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    cout << N - dp[N][N];
}