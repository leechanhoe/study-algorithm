#include <iostream>
using namespace std;

int dp[301][301];
int adj[301][301];
int N, M, K, a, b, c;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    while(K--){
        cin >> a >> b >> c;
        if(a < b){
            adj[a][b] = max(adj[a][b], c);
        }
    }

    for(int i = 2; i <= N; i++){
        dp[i][2] = adj[1][i];
        for(int j = 3; j <= i && j <= M; j++){
            dp[i][j] = dp[i][j-1];
            for(int k = 2; k < i; k++){
                if(adj[k][i] > 0 && dp[k][j-1] > 0)
                    dp[i][j] = max(dp[i][j], dp[k][j-1] + adj[k][i]);
            }
        }
    }
    cout << dp[N][M];
    return 0;
}