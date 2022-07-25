#include <iostream>
#include <vector>

#define MAXV 10002

using namespace std;

int V, E;
vector<vector<int>> adj;
int discovered[MAXV];
bool visit[MAXV];
int cnt = 0;
bool cutPoint[MAXV];

int dfs(int here, bool isRoot){
    discovered[here] = ++cnt;
    int child = 0;
    int ret = discovered[here];

    for (int i = 0; i < adj[here].size(); i++){
        int next = adj[here][i];

        if (discovered[next] == 0){ 
            child++;
            int subtree = dfs(next, false);
            if (!isRoot && subtree >= discovered[here]) // 절단점
                cutPoint[here] = true;
            ret = min(ret, subtree);
        }
        else // 역방향 간선일때
            ret = min(ret, discovered[next]);
    }

    if (isRoot && child > 1)
        cutPoint[here] = true;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> V >> E;
    adj.resize(V + 2);

    int a, b;
    int maxNode = 0;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        maxNode = max(maxNode, a);
        maxNode = max(maxNode, b);
    }

    for (int i = 1; i <= maxNode; i++)
    {
        if (discovered[i] == 0)
            dfs(i, true);
    }
    
    vector<int> result;
    for (int i = 0; i <= maxNode; i++){
        if (cutPoint[i] == true)
            result.push_back(i);
    }
    cout << result.size() << '\n';

    for (auto& ele : result)
        cout << ele << ' ';

    return 0;
}