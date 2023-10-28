#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int V, E, P;
vector<pair<int, int>> adj[10001];
int dist[10001];

int dijkstra(int s, int e){
    for(int i = 1; i <= V; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(now == e)
            return dist[now];
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int ncost = adj[now][i].second + cost;
            if(dist[next] < ncost)
                continue;
            
            dist[next] = ncost;
            pq.push({ncost, next});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E >> P;
    for(int i = 0, a, b, c; i < E; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    if(dijkstra(1, P) + dijkstra(P, V) == dijkstra(1, V))
        cout << "SAVE HIM";
    else
        cout << "GOOD BYE";
    return 0;
}