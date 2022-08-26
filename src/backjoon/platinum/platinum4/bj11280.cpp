#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> reGraph;
vector<int> scc;
stack<int> stk;
bool visit[20010];

void dfs(int x) {
    visit[x] = true;
    for(int next : graph[x]) {
        if(!visit[next])
            dfs(next);
    }
    stk.push(x); // 탐색 역순으로 스택에 넣어줌
}

// 한 정점에서 dfs로 탐색되는 정점은 같은 scc
void reDfs(int x, int sccId){
    visit[x] = true;
    scc[x] = sccId;
    for(int next : reGraph[x]) {
        if(!visit[next])
            reDfs(next, sccId);
    }
}

// 정점이 음수면 N보다 작게, 양수면 N보다 크게해서 서로 분리
int reverse(int x, int n){ // 이러면 not인 정점 < N 이됨
    return x > n ? x - n : x + n;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    graph.resize(N * 2 + 5);
    reGraph.resize(N * 2 + 5);
    scc.resize(N * 2 + 5);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        if(u < 0) // 일반정점과 not과는 N만큼의 차이를 가짐
            u = -u + N;
        if(v < 0)
            v = -v + N;

// A 가 false 일 경우 B 가 true 여야 하고, 반대로 B가 false일 경우 A가 true여야 함
// !A -> B, !B -> A
        graph[reverse(u, N)].push_back(v);
        graph[reverse(v, N)].push_back(u);
        reGraph[u].push_back(reverse(v, N));
        reGraph[v].push_back(reverse(u, N));
    }

    for(int i = 1; i <= 2*N + 1; i++){
        if(!visit[i])
            dfs(i);
    }
    memset(visit, false, sizeof(visit));

    int sccId = 1;
    while(!stk.empty()){
        int x = stk.top();
        stk.pop();
        if(!visit[x])
            reDfs(x, sccId++);
    }

    for(int i = 1; i <= N; i++){
        if(scc[i] == scc[i+N]){ // !a == a이면 실패
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}