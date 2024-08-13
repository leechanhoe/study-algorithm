#include <bits/stdc++.h>

using namespace std;
vector<string> mineral;
vector<int> pick;
map<string, int> m[3] = {{{"diamond", 1},{"iron", 1},{"stone", 1}},
                        {{"diamond", 5},{"iron", 1},{"stone", 1}},
                        {{"diamond", 25},{"iron", 5},{"stone", 1}}};
int mineral_num;
int ans;

void dfs(int idx, int num, int score){
    if(num == 0 || idx == mineral_num){
        ans = min(ans, score);
        return;
    }

    for(int i = 0; i < 3; i++){
        if(pick[i]){
            pick[i]--;
            int end = min(idx + 5, mineral_num);
            int plus = 0;
            for(int j = idx; j < end; j++){
                plus += m[i][mineral[j]];
            }
            dfs(end, num - 1, score + plus);
            pick[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    mineral = minerals;
    pick = picks;
    mineral_num = minerals.size();
    ans = 987654321;
    dfs(0, accumulate(pick.begin(), pick.end(), 0), 0);
    return ans;
}