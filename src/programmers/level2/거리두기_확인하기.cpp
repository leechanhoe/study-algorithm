#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool check(int i, int j, vector<string> place, bool visited[5][5]){
    visited[i][j] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});
    
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();
        
        if(d == 2){
            break;
        }
        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < 5 && 0 <= nc && nc < 5 && !visited[nr][nc] &&place[nr][nc] != 'X'){
                visited[nr][nc] = true;
                if(place[nr][nc] == 'P'){
                    return false;
                }
                q.push({{nr, nc}, d + 1});
            }
        }
    }
    return true;
}

bool check_place(vector<string> place){
    bool visited[5][5] = {false};
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(place[i][j] == 'P'){
                if(!check(i, j, place, visited)){
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int place = 0; place < 5; place++){
        if(check_place(places[place])){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }
    
    return answer;
}