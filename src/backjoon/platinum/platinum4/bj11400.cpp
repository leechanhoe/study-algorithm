#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;
int V, E;
vector<int> edge[MAX];
int visited[MAX];
vector<pair<int, int>> answer;

int dfs(int parent, int start, int order){
    int res = order;
    visited[start] = order; // DFS 탐색 순서 지정

    for (int i = 0; i < edge[start].size(); i++){
        int next = edge[start][i];
        if (parent == next)
            continue;

        if (visited[next] == 0) { // 다음 정점이 아직 탐색되지 않은 정점일 때
            int next_order = dfs(start, next, order + 1); // 다음 정점의 방문 번호를 찾고
            if (next_order > visited[start]) {
                /*
					현재 정점에서, 아직 방문하지 않은 정점의 방문 순서가 현재 정점의 순서보다 뒤라면
					현재 Edge는 단절선이 된다.(visited[Next] > visited[Start])
				*/
                answer.push_back(make_pair(min(start, next), max(start, next)));
            }
            res = min(res, next_order);
        }
        else{
            res = min(res, visited[next]);
            continue;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= V; i++){
        if (visited[i] == 0)
            dfs(0, i, 1);
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++){
        int s = answer[i].first;
        int e = answer[i].second;
        cout << s << ' ' << e << '\n';
    }
    return 0;
}