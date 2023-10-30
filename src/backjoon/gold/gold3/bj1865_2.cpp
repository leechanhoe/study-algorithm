#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int TC, N, M, W;
vector<pair<pair<int, int>, int>> v;
int dist[501];

void bellman(int n){
    for(int i = 0; i < n; i++){
        for(int loc = 0; loc < v.size(); loc++){
            int s = v[loc].first.first;
            int e = v[loc].first.second;
            int cost = v[loc].second;

            if(dist[s] + cost < dist[e])
                dist[e] = dist[s] + cost;
        }
    }

    for(int loc = 0; loc < v.size(); loc++){
        int s = v[loc].first.first;
        int e = v[loc].first.second;
        int cost = v[loc].second;
        if (dist[s] + cost < dist[e]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    cin >> TC;
    
    while(TC--){
        v.clear();
        for(int i = 0; i < N; i++){
            dist[i] = INF;
        }
        cin >> N >> M >> W;
        for(int i = 0, S, E, T; i < M; i++){
            cin >> S >> E >> T;
            v.push_back({{S, E}, T});
            v.push_back({{E, S}, T});
        }

        for (int i = 0, S, E, T; i < W; i++){
            cin >> S >> E >> T;
            v.push_back({{S, E}, -T});
        }

        bellman(N);
    }
}