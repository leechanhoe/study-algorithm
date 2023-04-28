#include <iostream>
#include <queue>
#include <vector>
#define INF 1987654321
using namespace std;

int dist[10001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    while(T--){
        int n, d, c;
        cin >> n >> d >> c;

        for(int i = 1; i <= n; i++)
            dist[i] = INF;
        dist[c] = 0;

        vector<pair<int, int>> adj[n+1];
        int a, b, s;
        for(int i = 0; i < d; i++){
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, c});
        while(!pq.empty()){
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if(dist[now] < cost)
                continue;

            for(int i = 0; i < adj[now].size(); i++){
                int ncost = cost + adj[now][i].second;
                int next = adj[now][i].first;

                if(ncost >= dist[next])
                    continue;

                dist[next] = ncost;
                pq.push({ncost, next});
            }
        }

        int infected = 0, time = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] != INF){
                infected++;
                time = max(time, dist[i]);
            }
        }
        cout << infected << ' ' << time << '\n';
    }
    return 0;
}