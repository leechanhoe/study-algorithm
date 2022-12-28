#include <iostream>
using namespace std;

int N, M, K, a, b, c, d;
long long dp[101][101];
bool block[101][101][2];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    while(K--){
        cin >> a >> b >> c >> d;
        if(a != c){
            if(a > c)
                block[a][b][0] = true;
            else
                block[c][d][0]= true;
        }
        else{
            if(b > d)
                block[a][b][1] = true;
            else
                block[c][d][1]= true;
        }
    }
    if(!block[1][0][0])
        dp[1][0] = 1;
    if(!block[0][1][1])
        dp[0][1] = 1;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(!block[i][j][0] && i > 0)
                dp[i][j] += dp[i-1][j];
            if(!block[i][j][1] && j > 0)
                dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[N][M];
    return 0;
}