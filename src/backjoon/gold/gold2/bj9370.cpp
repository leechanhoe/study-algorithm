#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 2001
#define INF 987654321
using namespace std;

int N, M, T, S, G, H;
int distS[MAX];
int distG[MAX];
int distH[MAX];
vector<pair<int, int>> adj[MAX];
vector<int> candi;

void dijkstra(int start, int dist[MAX]){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[now].size(); i++){
            int newCost = adj[now][i].second + cost;
            int next = adj[now][i].first;

            if (dist[next] > newCost){
                dist[next] = newCost;
                pq.push(make_pair(-newCost, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++){

        for (int i = 0; i < MAX; i++){
            adj[i].clear();
            distS[i] = INF;
            distG[i] = INF;
            distH[i] = INF;
        }
        candi.clear();
        
        cin >> N >> M >> T >> S >> G >> H;
        for(int i = 0; i < M; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }

        for (int i = 0; i < T; i++){
            int a;
            cin >> a;
            candi.push_back(a);
        }

        dijkstra(S, distS);
        dijkstra(H, distH);
        dijkstra(G, distG);
        int disthg = distH[G];

        sort(candi.begin(), candi.end());
        for(int i = 0; i < T; i++){
            int dest = candi[i];
            if (distS[H] + disthg + distG[dest] == distS[dest]
            || distS[G] + disthg + distH[dest] == distS[dest])
                cout << dest << ' ';
        }
        cout << '\n';
    }
}