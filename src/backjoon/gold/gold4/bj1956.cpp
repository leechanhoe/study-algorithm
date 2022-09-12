#include<iostream>
#define INF 4000001
using namespace std;

int adj[400][400];

int main() {
    int V, E, a, b, c;

    cin >> V >> E;
    for (int i = 0; i < 400; i++){
        for (int j = 0; j < 400; j++){
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++){
        cin >> a >> b >> c;
        adj[a- 1][b - 1] = c;
    }

    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (i == j)
                continue;
            if (adj[i][j] != INF && adj[j][i] != INF){
                ans = min(ans, adj[i][j] + adj[j][i]);
            }
        }
    }
    cout << (ans == INF ? -1 : ans);
}