#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[2001];
vector<int> adj[2001];

void dfs(int now, int d){
    if(d == 5){
        cout << 1;
        exit(0);
    }
    visit[now] = true;
    for(int next : adj[now]){
        if(!visit[next]){
            dfs(next, d + 1);
        }
    }
    visit[now] = false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        dfs(i, 1);
    }
    cout << 0;
    return 0;
}