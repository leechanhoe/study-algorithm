#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> adj(100001);
    for(auto& r : roads){
        adj[r[0]].push_back(r[1]);
        adj[r[1]].push_back(r[0]);
    }
    
    vector<int> dist(100001, -1);
    vector<bool> visited(100001, false);
    
    dist[destination] = 0;
    visited[destination] = true;
    queue<pair<int, int>> q;
    q.push({destination, 0});
    while(!q.empty()){
        int now = q.front().first;
        int d = q.front().second + 1;
        q.pop();
        for(auto& next : adj[now]){
            if(!visited[next]){
                visited[next] = true;
                dist[next] = d;
                q.push({next, d});
            }
        }
    }
    
    for(auto& s : sources){
        answer.push_back(dist[s]);
    }
    return answer;
}