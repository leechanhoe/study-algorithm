#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m, s, e;
vector<pair<int, int>> adj[1001];
int dist[1001];
int route[1001];

void dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > dist[now])
            continue;
            
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int ncost = adj[now][i].second + cost;
            if(dist[next] <= ncost)
                continue;

            route[next] = now;
            dist[next] = ncost;
            pq.push({ncost, next});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    cin >> s >> e;

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    dijkstra(s);

    vector<int> ansRoute;
    int tmp = e;
    while(tmp){
        ansRoute.push_back(tmp);
        tmp = route[tmp];
    }

    cout << dist[e] << '\n' << ansRoute.size() << '\n';
    for(int i = ansRoute.size() - 1; i >= 0; i--){
        cout << ansRoute[i] << ' ';
    }
    return 0;
}
