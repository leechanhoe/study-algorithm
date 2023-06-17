#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans;
int parent[1001];

int find(int x){
    if(x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a < b)
        parent[b] = a;
    else 
        parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> adj;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({c, {a, b}});
    }

    sort(adj.begin(), adj.end());
    for(int i = 0; i < M; i++){
        if(find(adj[i].second.first) != find(adj[i].second.second)){
            ans += adj[i].first;
            uni(adj[i].second.first, adj[i].second.second);
        }
    }

    cout << ans;
}