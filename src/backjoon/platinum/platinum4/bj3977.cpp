#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V, E;
vector<vector<int>> adj;
stack<int> st;
vector<int> visited_order;
vector<int> sccIndegree; // scc의 진입차수
vector<int> sccId; // 각 노드가 속한 scc 번호
vector<vector<int>> sccs;
int order, sccCnt;

int FindScc(int now){
    int min_order = visited_order[now] = ++order;
    int next;
    st.push(now);

    for(int i = 0; i < adj[now].size(); i++){
        next = adj[now][i];
        if(visited_order[next] == -1) // 방문하지 않은 노드면 
            min_order = min(min_order, FindScc(next)); // dfs
        else if(sccId[next] == -1) // 방문했는데 scc로 판명나지 않은 노드면 싸이클 발생
            min_order = min(min_order, visited_order[next]); // 그 노드의 최소 방문 순서를 얻는다
    }
    //DFS 재귀 방문을 마친 후에 간선을 끊을지 검사
    if(min_order == visited_order[now]){ // scc는 하나로만 이루어질수도 있음 
        int temp;
        vector<int> new_scc;
        while(1){ // 스택에 담긴 정점을 자신 정범 번호가 나올때까지 빼내 주면 
            temp = st.top(); // 해당 정점들은 모두 같은 scc에 속한다
            st.pop();
            sccId[temp] = sccCnt;
            new_scc.push_back(temp);
            if(temp == now)
                break;
        }
        sccs.push_back(new_scc);
        sccCnt++;
    }
    return min_order;
}

void solve(){
    cin >> V >> E;
    adj = vector<vector<int>>(V);
    visited_order = vector<int>(V, -1);
    sccId = vector<int>(V, -1);
    sccIndegree = vector<int>(V);
    sccs = vector<vector<int>>();
    sccCnt = 0;
    order = 0;

    int a, b;
    for (int i = 0; i < E; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 0; i < V; i++){
        if(visited_order[i] == -1)
            FindScc(i);
    }

    for(int i = 0; i < V; i++){
        for(auto &w : adj[i]){
            if(sccId[w] != sccId[i]) // 인접한 두 노드의 scc가 다르면
                sccIndegree[sccId[w]]++; // 연결당하는 노드의 scc의 진입차수 + 1
        }
    }

    // for(int i = 0; i < V; i++)
    //     cout << sccId[i] << ' ';
    // cout << '\n';
    // for(int i = 0; i < V; i++)
    //     cout << sccIndegree[i] << ' ';

    int ans = -1;
    int cnt = 0;
    for(int i = 0; i < sccs.size(); i++){
        if (sccIndegree[i] == 0){
            cnt++;
            if(cnt > 1){
                cout << "Confused" << '\n' << '\n';
                return;
            }
            ans = i;
        }
    }

    for(auto &a : sccs[ans])
        cout << a << '\n';
    cout << '\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}