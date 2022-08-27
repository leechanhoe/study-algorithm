#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v[5001];
bool visited[5001];
int works[5001];
int ans = 0;

bool dfs(int from){
    if(visited[from])
        return false;

    visited[from] = true;
    
    for(int i = 0; i < v[from].size(); i++){
        int to = v[from][i];
        //일하는사람이 없거나 / 있는데 방문안한 사람이고 dfs해서 일자리가 있으면
        if(works[to] == 0 || (!visited[works[to]] && dfs(works[to]))){
            works[to] = from;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for(int i = 1; i <= N; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i))
            ans++;
    }
    cout << ans;
}