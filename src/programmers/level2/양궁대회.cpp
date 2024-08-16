#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int max_score;
int now[11];
int ans[11];

void dfs(int arrow, int idx, vector<int> info){

    bool last = true;
    for(int i = idx + 1; i < 10; i++){
        if(info[i] < arrow){
            last = false;
            now[i] = info[i] + 1;
            dfs(arrow - info[i] - 1, i, info);
            now[i] = 0;
        }
    }

    if(last){
        int score = 0;
        for(int i = 0; i < 10; i++){
            if(info[i] == 0 && now[i] == 0) continue;

            if(info[i] < now[i])
                score += 10 - i;
            else
                score -= 10 - i;
        }
        if(0 < score && max_score < score){
            max_score = score;
            copy(now, now + 10, ans);
        }
        else if(0 < score && max_score == score){
            for (int i=10;i>=0;i--)
            {
                if (ans[i] > now[i]) return;
                else if (ans[i] < now[i])
                {
                    copy(now, now + 10, ans);
                    break;
                }
            }
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    dfs(n, -1, info);
    vector<int> answer(ans, ans + 10);
    int sum = accumulate(answer.begin(), answer.end(), 0);
    if (sum == 0){
        vector<int> v;
        v.push_back(-1);
        return v;
    }
    else{
        answer.push_back(n - sum);
    }
    return answer;
}