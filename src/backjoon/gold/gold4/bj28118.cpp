#include <bits/stdc++.h>
using namespace std;

vector<int> adj[41];
bool visited[41];
int N, M, ans;

void dfs(int now){
    for(auto next : adj[now]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = -1;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            ans++;
        }
    }

    cout << ans;
    return 0;
}