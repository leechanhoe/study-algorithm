#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int tc, n, m;
int ran[501], indegree[501];
bool adj[501][501];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> tc;
    while(tc--){
        memset(indegree, 0, sizeof(indegree));
        memset(adj, false, sizeof(adj));

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> ran[i];

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                adj[ran[i]][ran[j]] = true;
                indegree[ran[j]]++;
            }
        }

        cin >> m;
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;

            if(adj[a][b]){
                adj[a][b] = false;
                adj[b][a] = true;
                indegree[b]--;
                indegree[a]++;
            }
            else{
                adj[b][a] = false;
                adj[a][b] = true;
                indegree[a]--;
                indegree[b]++;
            }
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        for(int j = 0; j < n && !q.empty(); j++){
            int now = q.front();
            q.pop();
            ans.push_back(now);
            indegree[now] = -1;

            for(int i = 1; i <= n; i++){
                if(adj[now][i])
                    indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        if(ans.size() == n){
            for(int a : ans){
                cout << a << ' ';
            }
            cout << '\n';
        }
        else{
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}