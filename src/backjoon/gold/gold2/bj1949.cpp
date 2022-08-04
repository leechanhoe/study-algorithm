#include <iostream>
#include <vector>
using namespace std;

int N;
// now번 마을이 0(일반 마을)일 때 now번 마을을 루트로 하는 서브트리의 우수 마을들 인구수의 최댓값
// now번 마을이 1(우수 마을)일 때 now번 마을을 루트로 하는 서브트리의 우수 마을들 인구수의 최댓값
int dp[10001][2];
int popul[10001];
bool visited[10001];
vector<int> tree[10001];

void dfs(int now){
    visited[now] = true;
    dp[now][1] = popul[now];

    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        if(visited[next])
            continue;
        dfs(next);

        dp[now][0] += max(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> popul[i];

    int a, b;
    for (int i = 0; i < N-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}