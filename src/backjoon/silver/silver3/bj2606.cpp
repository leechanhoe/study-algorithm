#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans;
vector<int> adj[101];
bool visit[101];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(auto i : adj[c]){
            if(!visit[i]){
                q.push(i);
                ans++;
                visit[i] = true;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}