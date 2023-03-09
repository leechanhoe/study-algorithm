#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int N, M;
vector<pair<int, int>> adj[50001];
int dist[50001];

void dijkstra(int start){
    for(int i = 1; i <= N; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(auto next : adj[now]){
            int ncost = next.first + cost;
            if(dist[next.second] <= ncost)
                continue;

            dist[next.second] = ncost;
            pq.push({ncost, next.second});
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    dijkstra(1);
    cout << dist[N];
    return 0;
}