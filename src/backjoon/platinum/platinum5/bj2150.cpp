#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V, E;
vector<vector<int>> adj;
stack<int> st;
vector<int> visited_order;
vector<bool> is_scc;
vector<vector<int>> sccs;
int order = 0;

int FindScc(int now){
    int min_order = visited_order[now] = ++order;
    int next;
    st.push(now);

    for(int i = 0; i < adj[now].size(); i++){
        next = adj[now][i];
        if(visited_order[next] == -1) // 방문하지 않은 노드면 
            min_order = min(min_order, FindScc(next)); // dfs
        else if(!is_scc[next]) // 방문했는데 scc로 판명나지 않은 노드면 싸이클 발생
            min_order = min(min_order, visited_order[next]); // 그 노드의 최소 방문 순서를 얻는다
    }
    //DFS 재귀 방문을 마친 후에 간선을 끊을지 검사
    if(min_order == visited_order[now]){ // scc는 하나로만 이루어질수도 있음 
        int temp;
        vector<int> new_scc;
        while(1){ // 스택에 담긴 정점을 자신 정범 번호가 나올때까지 빼내 주면 
            temp = st.top(); // 해당 정점들은 모두 같은 scc에 속한다
            st.pop();
            is_scc[temp] = true;
            new_scc.push_back(temp);
            if(temp == now)
                break;
        }
        sccs.push_back(new_scc);
    }
    return min_order;
}

bool Comp(vector<int>& va, vector<int>& vb){
    return va[0] < vb[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    adj = vector<vector<int>>(V + 1);
    is_scc = vector<bool>(V + 1, false);
    visited_order = vector<int>(V + 1, -1);

    int a, b;
    for (int i = 0; i < E; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i < V + 1; i++){
        if(visited_order[i] == -1)
            FindScc(i);
    }

    for(int i = 0; i < sccs.size(); i++)
        sort(sccs[i].begin(), sccs[i].end());
    sort(sccs.begin(), sccs.end(), Comp);

    cout << sccs.size() << '\n';
    for(int i = 0; i < sccs.size(); i++){
        for(int j = 0; j < sccs[i].size(); ++j)
            cout << sccs[i][j] << ' ';
        cout << "-1\n";
    }
    return 0;
}