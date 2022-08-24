#include <bits/stdc++.h>
using namespace std;

int N;
int t[501], dp[501], ind[501];
vector<int> precede[501];

int main() {
    cin >> N;

    for(int i = 1; i <= N; i++){
        int pre;
        cin >> t[i];
        dp[i] = t[i];
        while(1){
            cin >> pre;
            if(pre == -1)
                break;
            precede[pre].push_back(i);
            ind[i]++;
        }
    }
    queue<int> ind0;
    for(int i = 1; i <= N; i++){
        if(ind[i] == 0)
            ind0.push(i);
    }

    while(!ind0.empty()){
        int now = ind0.front();
        ind0.pop();
        for(int i = 0; i < precede[now].size(); i++){
            int next = precede[now][i];
            dp[next] = max(dp[next], dp[now] + t[next]);

            ind[next]--;
            if(ind[next] == 0)
                ind0.push(next);
        }
    }

    for (int i = 1; i <= N; i++){
        cout << dp[i] << '\n';
    }
}