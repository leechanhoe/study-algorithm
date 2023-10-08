#include <bits/stdc++.h>
using namespace std;

int N, M, S;
int parent[2001];
int order[2001];
vector<pair<int, pair<int, int>>> edge;

int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> S;
    for(int i = 1; i <= N; i++)
        parent[i] = i;
    
    for(int i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end());

    for(int i = 0; i < N; i++)
        cin >> order[i];

    int ans = 0;
    int visited = 1;
    for(int i = 0; i < M; i++){
        if (find(edge[i].second.first) != find(edge[i].second.second)){
            uni(edge[i].second.first, edge[i].second.second);
            ans += edge[i].first;
            visited++;
            if(visited == N)
                break;
        }
    }

    cout << ans;
    return 0;
}