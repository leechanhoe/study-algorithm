#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> sir[51];
int N;

int dfs(int now){
    if(sir[now].size() == 0)
        return 0;
    
    for(auto& sub : sir[now]){
        sub.first = dfs(sub.second);
    }
    sort(sir[now].begin(), sir[now].end(), greater<pair<int, int>>());

    int max_ = 0;
    for(int i = 0; i < sir[now].size(); i++){
        max_ = max(max_, sir[now][i].first + i + 1);
    }
    return max_;
}

int main(){
    cin >> N;
    for(int i = 0, s; i < N; i++){
        cin >> s;
        if(i == 0)
            continue;
        sir[s].push_back({0, i});
    }

    cout << dfs(0);
    return 0;
}