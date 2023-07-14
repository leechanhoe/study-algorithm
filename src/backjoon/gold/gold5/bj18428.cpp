#include <iostream>
#include <vector>
using namespace std;

int N;
char map[6][6];
bool visit[6][6];
vector<pair<int, int>> t;
bool ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isS(){
    for(auto loc : t){
        for(int i = 0; i < 4; i++){
            for(int j = 1; j < N; j++){
                int nr = loc.first + dr[i] * j;
                int nc = loc.second + dc[i] * j;
                if(!(0 <= nr && nr < N && 0 <= nc && nc < N))
                    break;
                
                if(map[nr][nc] == 'O')
                    break;
                
                if(map[nr][nc] == 'S')
                    return true;
            }
        }
    }
    return false;
}

void dfs(int r, int c, int n){
    if(n == 3){
        if(!isS()){
            ans = true;
        }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++)
        //         cout << map[i][j] << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
        return;
    }

    for(int i = r; i < N; i++){
        for(int j = (i == r ? c : 0); j < N; j++){
            if(map[i][j] == 'X'){
                map[i][j] = 'O';
                dfs(i, j, n + 1);
                map[i][j] = 'X';
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 'T')
                t.push_back({i, j});
        }
    }

    dfs(0, 0, 0);
    cout << (ans ? "YES" : "NO");
    return 0;
}