#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool visit[26][26];
string map[26];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
vector<int> home_num;
int groop_num;

int dfs(int r, int c){
    visit[r][c] = true;
    int num = 1;
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(0 <= nr && nr < N && 0 <= nc && nc < N && map[nr][nc] == '1' && !visit[nr][nc]){
            num += dfs(nr, nc);
        }
    }
    return num;
}

int main() {
   cin >> N;
    for(int i = 0; i < N; i++){
        cin >> map[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == '1' && !visit[i][j]){
                home_num.push_back(dfs(i, j));
                groop_num++;
            }
        }
    }

    sort(home_num.begin(), home_num.end());
    cout << groop_num << '\n';
    for(auto num : home_num){
        cout << num << '\n';
    }
    return 0;
}