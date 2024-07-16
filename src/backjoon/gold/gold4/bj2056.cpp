#include <bits/stdc++.h>
using namespace std;

int N;
int dp[10001];
int indegree[10001];
int t[10001];
vector<int> pre[10001];
queue<int> q;

int main(){
    cin >> N;
    for(int i = 1; i <= N ;i++){
        cin >> t[i] >> indegree[i];
        dp[i] = t[i];
        for(int j = 0; j < indegree[i]; j++){
            int x;
            cin >> x;
            pre[x].push_back(i);
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < pre[now].size(); i++){
            int next = pre[now][i];
            dp[next] = max(dp[next], dp[now] + t[next]);
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    cout << *max_element(dp, dp + N + 1);
    return 0;
}