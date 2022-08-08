#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<vector<int>> adj; // 인접 행렬
vector<int> stk;
int visited_order[100001]; // 각 노드의 방문 순서
int sccId[100001]; // 각 노드가 속한 scc 번호
int order, sccCnt; // 방문 순서를 지정하기위한 변수 / scc의 개수
int sccindegree[100001]; //

int FindScc(int now){
    int min_order = visited_order[now] = order++;
    stk.push_back(now);

    for(auto &next : adj[now]){
        if(visited_order[next] == -1)
            min_order = min(min_order, FindScc(next));
        else if(sccId[next] == -1)  // 방문했는데 scc로 판명나지 않은 노드면 싸이클 발생
            min_order = min(min_order, visited_order[next]); // 그 노드의 최소 방문 순서를 얻는다
    }
 // DFS 재귀 방문을 마친 후에 간선을 끊을지 검사
    if(min_order == visited_order[now]){ // scc는 하나로만 이루어질수도 있음 
        while(1){ // 스택에 담긴 정점을 자신 정범 번호가 나올때까지 빼내 주면 
            int temp = stk.back(); // 해당 정점들은 모두 같은 scc에 속한다
            stk.pop_back();
            sccId[temp] = sccCnt;
            if(temp == now)
                break;
        }
        sccCnt++;
    }
    return min_order;
}

void init(){
    memset(visited_order, -1, sizeof(visited_order));
    memset(sccId, -1, sizeof(sccId));
    memset(sccindegree, 0, sizeof(sccindegree));
    adj.clear();
    adj.resize(N + 1, vector<int>());
    order = sccCnt = 0;

    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void solve(){
    int result = 0;

    for(int i = 1; i <= N; i++){
        if(visited_order[i] == -1)
            FindScc(i);
    }

    for(int i = 1; i <= N; i++){
        for(auto &w : adj[i]){
            if(sccId[w] != sccId[i]) // 인접한 두 노드의 scc가 다르면
                sccindegree[sccId[w]]++; // 연결당하는 노드의 scc의 진입차수 + 1
        }
    }

    for(int i = 1; i <= N; i++)
        cout << sccindegree[i] << ' ';

    for(int i = 0; i < sccCnt; i++){
        if(!sccindegree[i])
            result++;
    }

    cout << result << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while(test--){
        cin >> N >> M;
        init();
        solve();
    }
    return 0;
}