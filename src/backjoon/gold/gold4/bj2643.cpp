#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
pair<int, int> paper[101];
int dp[101];

bool check(pair<int, int> a, pair<int, int> b){
    if (a.first >= b.first && a.second >= b.second) 
        return true;
	if (a.first >= b.second && a.second >= b.first) 
        return true;
	return false;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first * a.second > b.first * b.second;
}

int solve(int idx){
    if(idx == N + 1)
        return 0;

    if(dp[idx] != -1)
        return dp[idx];

    dp[idx] = 0;
    for(int i = idx + 1; i <= N + 1; i++){
            for(int i = 1; i <= N; i++){
        if(check(paper[idx], paper[i])){
            dp[idx] = max(dp[idx], solve(i) + 1);
        }
    }
    return dp[idx];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    paper[0] = {1000, 1000};
    for(int i = 1; i <= N; i++){
        cin >> paper[i].first >> paper[i].second;
    }

    sort(paper, paper + N + 1, cmp);
    memset(dp, -1, sizeof(dp));
    cout << solve(0) - 1 << '\n';
    return 0;
}