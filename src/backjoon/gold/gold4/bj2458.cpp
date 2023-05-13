#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M;
int adj[501][501];

int main(){
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        int cnt = 0;
        for(int j = 1; j <= N; j++){
            if(adj[i][j] != INF || adj[j][i] != INF){
                cnt++;
            }
        }
        if(cnt == N - 1)
            ans++;
    }
    cout << ans;
    return 0;
}