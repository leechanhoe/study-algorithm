#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<string>& a, vector<string>& b){
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    stack<int> stk;
    map<int, string> id;
    vector<int> start;
    vector<int> remain;
    
    int id_idx = 0;
    for(auto& plan : plans){
        id[id_idx++] = plan[0];
        int t = stoi(plan[1].substr(0, 2)) * 60 + stoi(plan[1].substr(3, 2));
        start.push_back(t);
        remain.push_back(stoi(plan[2]));
    }
    
    int i = 0;
    int new_study = 0;
    bool study = false;
    for(int now = 0; now < 100000; now++){
        if(study && remain[i] == 0){
            answer.push_back(plans[i][0]);
            if(!stk.empty()){
                i = stk.top();
                stk.pop();
            }
            else{
                study = false;
            }
        }
        
        if(now == start[new_study]){
            if(!study)
                study = true;
            else{
                stk.push(i);
            }
            i = new_study;
            new_study++;
            if(new_study == plans.size() + 1)
                break;
        }
        
        if(study)
            remain[i]--;
    }
    return answer;
}