#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int farm;
int N, M, ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> farm;
            if(farm == 0){
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
            else
                dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}