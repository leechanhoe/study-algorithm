#include <iostream>
#include <vector>
using namespace std;

int N, M;
int h[5001];
vector<int> adj[5001];
int dp[5001];

int dfs(int now){
    if(dp[now])
        return dp[now];

    int ret = 0;
    for(int i = 0; i < adj[now].size(); i++){
        if(h[now] < h[adj[now][i]])
            ret = max(ret, dfs(adj[now][i]));
    }
    return dp[now] = ret + 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> h[i];
    }
    
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        if(h[s] < h[e])
            adj[s].push_back(e);
        else
            adj[e].push_back(s);
    }

    for(int i = 1; i <= N; i++){
        dfs(i);
        cout << dp[i] << '\n';
    }
    return 0;
}